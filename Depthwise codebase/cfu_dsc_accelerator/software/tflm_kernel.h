/*******************************************************************************
 * CFU DSC Accelerator - TensorFlow Lite Micro Integration
 *
 * TFLM kernel implementation for DepthwiseConv2D using the CFU accelerator.
 * This enables automatic offloading of MobileNetV2 bottleneck blocks.
 ******************************************************************************/

#ifndef CFU_DSC_TFLM_KERNEL_H
#define CFU_DSC_TFLM_KERNEL_H

#include "tensorflow/lite/micro/micro_common.h"
#include "tensorflow/lite/micro/kernels/kernel_util.h"
#include "cfu_dsc_driver.h"

namespace tflite {
namespace {

//------------------------------------------------------------------------------
// CFU DSC OpData
//------------------------------------------------------------------------------
struct CFUDSCData {
    // Cached tensor dimensions
    TfLitePadding padding;
    int stride_width;
    int stride_height;
    int dilation_width_factor;
    int dilation_height_factor;
    int depth_multiplier;

    // Quantization parameters
    int32_t input_zero_point;
    int32_t output_zero_point;
    int32_t output_multiplier;
    int output_shift;

    // Per-channel quantization
    const int32_t* per_channel_output_multiplier;
    const int32_t* per_channel_output_shift;

    // CFU configuration
    cfu_dsc_config_t cfu_config;
};

//------------------------------------------------------------------------------
// TensorFlow Lite Micro Kernel Functions
//------------------------------------------------------------------------------

/**
 * Prepare function - called during graph initialization
 */
TfLiteStatus CFUDSCPrepare(TfLiteContext* context, TfLiteNode* node);

/**
 * Eval function - called during inference
 * Handles both float and int8 quantized inputs
 */
TfLiteStatus CFUDSCEval(TfLiteContext* context, TfLiteNode* node);

/**
 * Reset function - called to reset accelerator state
 */
TfLiteStatus CFUDSCReset(TfLiteContext* context, TfLiteNode* node);

//------------------------------------------------------------------------------
// Registration
//------------------------------------------------------------------------------

// Custom op registration for DepthwiseConv2D with CFU acceleration
TfLiteRegistration Register_CFUDSC_DEPTHWISE_CONV_2D();

// Registration for fused bottleneck block (Expansion + Depthwise + Projection)
TfLiteRegistration Register_CFUDSC_BOTTLENECK_BLOCK();

}  // namespace
}  // namespace tflite

#endif // CFU_DSC_TFLM_KERNEL_H
