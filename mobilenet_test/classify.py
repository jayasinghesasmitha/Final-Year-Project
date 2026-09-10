import tensorflow as tf
import numpy as np
from PIL import Image
import time
import csv


# ============================================================
# CONFIGURATION
# ============================================================

IMAGE_PATH = "images/cat.jpg"
CSV_PATH = "mobilenet_v2_timing.csv"

# Number of measurements for each operation
# Increase to 20 or 30 if you want more stable measurements.
NUM_RUNS = 10


# ============================================================
# HELPER FUNCTION
# ============================================================

def measure_model(model_to_measure, input_tensor, runs=10):
    """
    Measure the execution time of a Keras model.

    A few warm-up runs are performed first because TensorFlow
    may perform initialization on the first execution.
    """

    # Warm-up
    for _ in range(3):
        output = model_to_measure(input_tensor, training=False)

        if isinstance(output, (tf.Tensor, tf.Variable)):
            output.numpy()

    times = []

    for _ in range(runs):

        start = time.perf_counter()

        output = model_to_measure(
            input_tensor,
            training=False
        )

        # Force TensorFlow to finish
        if isinstance(output, (tf.Tensor, tf.Variable)):
            output.numpy()

        end = time.perf_counter()

        elapsed_ms = (end - start) * 1000

        times.append(elapsed_ms)

    return {
        "average": np.mean(times),
        "minimum": np.min(times),
        "maximum": np.max(times)
    }


# ============================================================
# 1. LOAD MODEL
# ============================================================

print("=" * 90)
print("LOADING MOBILENETV2")
print("=" * 90)

model_start = time.perf_counter()

model = tf.keras.applications.MobileNetV2(
    weights="imagenet"
)

model_end = time.perf_counter()

model_loading_time = (
    model_end - model_start
)

print(
    f"Model loading time: "
    f"{model_loading_time * 1000:.2f} ms"
)


# ============================================================
# 2. LOAD IMAGE
# ============================================================

print("\n")
print("=" * 90)
print("LOADING IMAGE")
print("=" * 90)

print(f"Image: {IMAGE_PATH}")

image = Image.open(
    IMAGE_PATH
).convert("RGB")

print(
    f"Original image size: {image.size}"
)


# ============================================================
# 3. PREPROCESS IMAGE
# ============================================================

preprocess_start = time.perf_counter()

image = image.resize(
    (224, 224)
)

image_array = np.array(
    image,
    dtype=np.float32
)

image_array = np.expand_dims(
    image_array,
    axis=0
)

image_array = (
    tf.keras.applications.mobilenet_v2
    .preprocess_input(image_array)
)

x = tf.convert_to_tensor(
    image_array,
    dtype=tf.float32
)

preprocess_end = time.perf_counter()

preprocess_time = (
    preprocess_end - preprocess_start
)

print(
    f"Preprocessing time: "
    f"{preprocess_time * 1000:.2f} ms"
)


# ============================================================
# 4. WARM UP COMPLETE MODEL
# ============================================================

print("\n")
print("=" * 90)
print("WARMING UP COMPLETE MODEL")
print("=" * 90)

for _ in range(5):

    output = model(
        x,
        training=False
    )

    output.numpy()

print("Warm-up completed.")


# ============================================================
# 5. NORMAL MOBILENETV2 INFERENCE
# ============================================================

print("\n")
print("=" * 90)
print("NORMAL MOBILENETV2 INFERENCE")
print("=" * 90)

normal_times = []

for _ in range(NUM_RUNS):

    start = time.perf_counter()

    predictions = model(
        x,
        training=False
    )

    # Force completion
    predictions.numpy()

    end = time.perf_counter()

    normal_times.append(
        (end - start) * 1000
    )


normal_average = np.mean(
    normal_times
)

normal_min = np.min(
    normal_times
)

normal_max = np.max(
    normal_times
)

print(
    f"Average inference time : "
    f"{normal_average:.2f} ms"
)

print(
    f"Minimum inference time : "
    f"{normal_min:.2f} ms"
)

print(
    f"Maximum inference time : "
    f"{normal_max:.2f} ms"
)


# ============================================================
# 6. PREDICTION
# ============================================================

predictions = model(
    x,
    training=False
)

predictions_numpy = predictions.numpy()

results = (
    tf.keras.applications.mobilenet_v2
    .decode_predictions(
        predictions_numpy,
        top=5
    )[0]
)


print("\n")
print("=" * 90)
print("TOP 5 PREDICTIONS")
print("=" * 90)

print()

for _, label, probability in results:

    print(
        f"{label:30s}"
        f"{probability * 100:8.2f}%"
    )


# ============================================================
# 7. LIST ALL CONVOLUTION LAYERS
# ============================================================

print("\n")
print("=" * 90)
print("FINDING CONVOLUTION LAYERS")
print("=" * 90)

conv_layers = []

for layer in model.layers:

    if isinstance(
        layer,
        tf.keras.layers.Conv2D
    ):

        conv_layers.append(layer)


print(
    f"\nFound {len(conv_layers)} Conv2D layers."
)


# ============================================================
# 8. LIST DEPTHWISE LAYERS
# ============================================================

depthwise_layers = []

for layer in model.layers:

    if isinstance(
        layer,
        tf.keras.layers.DepthwiseConv2D
    ):

        depthwise_layers.append(layer)


print(
    f"Found {len(depthwise_layers)} "
    f"DepthwiseConv2D layers."
)


# ============================================================
# 9. DISPLAY CONVOLUTION STRUCTURE
# ============================================================

print("\n")
print("=" * 90)
print("MOBILENETV2 CONVOLUTION STRUCTURE")
print("=" * 90)

print()

print(
    f"{'Layer':45s}"
    f"{'Type':25s}"
    f"{'Kernel':15s}"
    f"{'Filters':10s}"
)

print("-" * 95)


for layer in model.layers:

    if isinstance(
        layer,
        tf.keras.layers.Conv2D
    ):

        kernel = layer.kernel_size
        filters = layer.filters

        print(
            f"{layer.name:45s}"
            f"{'Conv2D':25s}"
            f"{str(kernel):15s}"
            f"{str(filters):10s}"
        )


    elif isinstance(
        layer,
        tf.keras.layers.DepthwiseConv2D
    ):

        kernel = layer.kernel_size

        print(
            f"{layer.name:45s}"
            f"{'DepthwiseConv2D':25s}"
            f"{str(kernel):15s}"
            f"{'depthwise':10s}"
        )


# ============================================================
# 10. PROFILE CONVOLUTION LAYERS
# ============================================================

print("\n")
print("=" * 90)
print("PROFILING CONVOLUTION LAYERS")
print("=" * 90)

print()

timing_results = []


for layer in model.layers:

    # --------------------------------------------------------
    # Only profile convolution operations
    # --------------------------------------------------------

    is_conv = isinstance(
        layer,
        tf.keras.layers.Conv2D
    )

    is_depthwise = isinstance(
        layer,
        tf.keras.layers.DepthwiseConv2D
    )

    if not (is_conv or is_depthwise):
        continue


    # --------------------------------------------------------
    # Get layer input/output
    # --------------------------------------------------------

    try:

        layer_input = layer.input
        layer_output = layer.output

    except Exception as e:

        print(
            f"Skipping {layer.name}: "
            f"cannot access graph tensors."
        )

        continue


    # --------------------------------------------------------
    # Create a small model representing this layer
    # --------------------------------------------------------

    try:

        layer_model = tf.keras.Model(
            inputs=layer_input,
            outputs=layer_output
        )

    except Exception as e:

        print(
            f"Skipping {layer.name}: "
            f"cannot create profiling model."
        )

        continue


    # --------------------------------------------------------
    # Create input tensor for this layer
    # --------------------------------------------------------

    try:

        prefix_model = tf.keras.Model(
            inputs=model.input,
            outputs=layer_input
        )

        layer_input_value = prefix_model(
            x,
            training=False
        )

    except Exception as e:

        print(
            f"Skipping {layer.name}: "
            f"cannot generate layer input."
        )

        continue


    # --------------------------------------------------------
    # Measure
    # --------------------------------------------------------

    result = measure_model(
        layer_model,
        layer_input_value,
        NUM_RUNS
    )


    # --------------------------------------------------------
    # Determine operation
    # --------------------------------------------------------

    if is_depthwise:

        operation = "Depthwise 3x3"

    else:

        name = layer.name.lower()

        if "expand" in name:

            operation = "Expansion 1x1"

        elif "project" in name:

            operation = "Projection 1x1"

        else:

            operation = "Other Conv2D"


    # --------------------------------------------------------
    # Store
    # --------------------------------------------------------

    timing_results.append(
        {
            "layer": layer.name,
            "type": layer.__class__.__name__,
            "operation": operation,
            "average_ms": result["average"],
            "minimum_ms": result["minimum"],
            "maximum_ms": result["maximum"]
        }
    )


# ============================================================
# 11. PRINT TIMING RESULTS
# ============================================================

print("\n")
print("=" * 110)
print("CONVOLUTION TIMING RESULTS")
print("=" * 110)

print()

print(
    f"{'Layer':40s}"
    f"{'Operation':22s}"
    f"{'Average (ms)':15s}"
    f"{'Min (ms)':15s}"
    f"{'Max (ms)':15s}"
)

print("-" * 110)


for result in timing_results:

    print(
        f"{result['layer']:40s}"
        f"{result['operation']:22s}"
        f"{result['average_ms']:15.4f}"
        f"{result['minimum_ms']:15.4f}"
        f"{result['maximum_ms']:15.4f}"
    )


# ============================================================
# 12. CALCULATE OPERATION TOTALS
# ============================================================

expansion_total = 0.0
depthwise_total = 0.0
projection_total = 0.0
other_conv_total = 0.0


for result in timing_results:

    operation = result["operation"]
    time_ms = result["average_ms"]


    if operation == "Expansion 1x1":

        expansion_total += time_ms


    elif operation == "Depthwise 3x3":

        depthwise_total += time_ms


    elif operation == "Projection 1x1":

        projection_total += time_ms


    elif operation == "Other Conv2D":

        other_conv_total += time_ms


bottleneck_total = (
    expansion_total
    + depthwise_total
    + projection_total
)


# ============================================================
# 13. OPERATION SUMMARY
# ============================================================

print("\n")
print("=" * 90)
print("MOBILENETV2 OPERATION SUMMARY")
print("=" * 90)

print()

print(
    f"Expansion 1x1 total     : "
    f"{expansion_total:.4f} ms"
)

print(
    f"Depthwise 3x3 total     : "
    f"{depthwise_total:.4f} ms"
)

print(
    f"Projection 1x1 total    : "
    f"{projection_total:.4f} ms"
)

print(
    f"Other Conv2D total      : "
    f"{other_conv_total:.4f} ms"
)

print(
    f"------------------------------------------"
)

print(
    f"Total bottleneck conv   : "
    f"{bottleneck_total:.4f} ms"
)


# ============================================================
# 14. TIME CONTRIBUTION
# ============================================================

print("\n")
print("=" * 90)
print("TIME CONTRIBUTION")
print("=" * 90)

print()

if normal_average > 0:

    expansion_percentage = (
        expansion_total
        / normal_average
    ) * 100

    depthwise_percentage = (
        depthwise_total
        / normal_average
    ) * 100

    projection_percentage = (
        projection_total
        / normal_average
    ) * 100

    bottleneck_percentage = (
        bottleneck_total
        / normal_average
    ) * 100


    print(
        f"Expansion 1x1      : "
        f"{expansion_percentage:.2f}%"
    )

    print(
        f"Depthwise 3x3      : "
        f"{depthwise_percentage:.2f}%"
    )

    print(
        f"Projection 1x1     : "
        f"{projection_percentage:.2f}%"
    )

    print(
        f"All bottlenecks    : "
        f"{bottleneck_percentage:.2f}%"
    )


# ============================================================
# 15. SAVE CSV
# ============================================================

print("\n")
print("=" * 90)
print("SAVING RESULTS")
print("=" * 90)

with open(
    CSV_PATH,
    "w",
    newline=""
) as file:

    writer = csv.writer(file)

    writer.writerow(
        [
            "Layer",
            "Type",
            "Operation",
            "Average_ms",
            "Minimum_ms",
            "Maximum_ms"
        ]
    )

    for result in timing_results:

        writer.writerow(
            [
                result["layer"],
                result["type"],
                result["operation"],
                result["average_ms"],
                result["minimum_ms"],
                result["maximum_ms"]
            ]
        )


print(
    f"Saved timing results to:"
)

print(
    f"{CSV_PATH}"
)


# ============================================================
# 16. FINAL SUMMARY
# ============================================================

print("\n")
print("=" * 90)
print("FINAL SUMMARY")
print("=" * 90)

print()

print(
    f"{'Model loading':35s}: "
    f"{model_loading_time * 1000:.2f} ms"
)

print(
    f"{'Image preprocessing':35s}: "
    f"{preprocess_time * 1000:.2f} ms"
)

print(
    f"{'MobileNetV2 inference (average)':35s}: "
    f"{normal_average:.2f} ms"
)

print(
    f"{'MobileNetV2 inference (minimum)':35s}: "
    f"{normal_min:.2f} ms"
)

print(
    f"{'MobileNetV2 inference (maximum)':35s}: "
    f"{normal_max:.2f} ms"
)

print()

print(
    f"{'Expansion 1x1':35s}: "
    f"{expansion_total:.4f} ms"
)

print(
    f"{'Depthwise 3x3':35s}: "
    f"{depthwise_total:.4f} ms"
)

print(
    f"{'Projection 1x1':35s}: "
    f"{projection_total:.4f} ms"
)

print(
    f"{'Bottleneck operations':35s}: "
    f"{bottleneck_total:.4f} ms"
)

print()

print("=" * 90)
print("DONE")
print("=" * 90)