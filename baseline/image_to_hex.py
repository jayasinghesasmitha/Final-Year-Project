#!/usr/bin/env python3

from pathlib import Path
from PIL import Image
import sys


# ============================================================
# Configuration
# ============================================================

IMAGE_SIZE = (224, 224)

# Project root = directory containing this script
ROOT_DIR = Path(__file__).resolve().parent

INPUT_IMAGE = ROOT_DIR / "inputs" / "img.jpg"
OUTPUT_DIR = ROOT_DIR / "generated"
OUTPUT_HEX = OUTPUT_DIR / "image.hex"


# ============================================================
# Main
# ============================================================

def main():
    print("=" * 60)
    print("MobileNetV2 Image -> HEX Converter")
    print("=" * 60)

    # --------------------------------------------------------
    # Check input image
    # --------------------------------------------------------
    if not INPUT_IMAGE.exists():
        print(f"ERROR: Input image not found:")
        print(f"       {INPUT_IMAGE}")
        sys.exit(1)

    print(f"Input image : {INPUT_IMAGE}")

    # --------------------------------------------------------
    # Create generated directory if necessary
    # --------------------------------------------------------
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

    # --------------------------------------------------------
    # Open image
    # --------------------------------------------------------
    try:
        image = Image.open(INPUT_IMAGE)

        print(f"Original size: {image.size}")
        print(f"Original mode: {image.mode}")

        # Convert to RGB
        image = image.convert("RGB")

        # Resize to MobileNetV2 input resolution
        image = image.resize(
            IMAGE_SIZE,
            Image.Resampling.BILINEAR
        )

    except Exception as e:
        print(f"ERROR: Could not process image:")
        print(f"       {e}")
        sys.exit(1)

    print(f"Output size  : {image.size}")
    print(f"Output mode  : {image.mode}")

    # --------------------------------------------------------
    # Get RGB pixel data
    # --------------------------------------------------------
    pixels = list(image.getdata())

    expected_pixels = 224 * 224

    if len(pixels) != expected_pixels:
        print(
            f"ERROR: Expected {expected_pixels} pixels, "
            f"got {len(pixels)}"
        )
        sys.exit(1)

    # --------------------------------------------------------
    # Write HEX file
    #
    # Format:
    #
    #   R
    #   G
    #   B
    #   R
    #   G
    #   B
    #   ...
    #
    # 224 * 224 * 3 = 150,528 bytes
    # --------------------------------------------------------
    with open(OUTPUT_HEX, "w") as f:

        for r, g, b in pixels:
            f.write(f"{r:02X}\n")
            f.write(f"{g:02X}\n")
            f.write(f"{b:02X}\n")

    # --------------------------------------------------------
    # Verify generated file
    # --------------------------------------------------------
    expected_bytes = 224 * 224 * 3

    with open(OUTPUT_HEX, "r") as f:
        lines = [line.strip() for line in f if line.strip()]

    if len(lines) != expected_bytes:
        print(
            f"ERROR: HEX file contains {len(lines)} values, "
            f"expected {expected_bytes}"
        )
        sys.exit(1)

    # --------------------------------------------------------
    # Print summary
    # --------------------------------------------------------
    print()
    print("SUCCESS")
    print("-" * 60)
    print(f"Image       : {INPUT_IMAGE.name}")
    print(f"Resolution  : 224 x 224")
    print(f"Channels    : RGB")
    print(f"Pixels      : {expected_pixels}")
    print(f"Bytes       : {expected_bytes}")
    print(f"HEX file    : {OUTPUT_HEX}")
    print(f"HEX values  : {len(lines)}")
    print("-" * 60)

    print()
    print("First 12 RGB bytes:")

    for i, value in enumerate(lines[:12]):
        print(f"  [{i:6d}] {value}")

    print()
    print("image.hex is ready for the Vivado simulation.")


if __name__ == "__main__":
    main()