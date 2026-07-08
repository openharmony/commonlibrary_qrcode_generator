# QR Code Generator

## Introduction

The QR Code Generator provides QR code generation capability for the OpenHarmony system. QR code is a widely-used encoding technology that has stood the test of market verification. It offers high information capacity, reliability, and strong confidentiality and anti-counterfeiting features. The QR Code Generator follows the [**ISO/IEC 18004:2015 standard**](https://www.iso.org/obp/ui/es/#iso:std:iso-iec:18004:ed-3:v1:en), supporting QR Code generation from Version 1 to Version 40, with flexible error correction level options.

-   **Encoding Mode Support:** The QR Code Generator supports Numeric mode, Alphanumeric mode, and Byte mode, meeting data encoding requirements for different scenarios.
-   **Error Correction Capability:** Depending on the error correction level, QR codes can be successfully decoded even when 25% to 30% of the codewords are obscured, ensuring the QR code can still be scanned even when partially damaged.
-   **Memory Management:** Provides custom memory allocation hooks, allowing developers to inject their own memory management functions for memory optimization on embedded devices.
-   **Form Support:** Supports three forms: standard, mini, and small. The standard form is used for the QRCode control, the mini form is used for the UIQrcode control, and the small form is not currently used by any control.

## System Architecture

**Figure 1**  QR Code Generator Architecture

![](figures/qrcode_generator.png "QR Code Generator Architecture")

-   **External Interface Layer:** Provides internal API interfaces for QR code generation, including image encoding and memory management.

-   **Data Encoding:** Parses and encodes input character stream information, including String Parser, Version Selection, Data Segmentation, Code Assembly, RS Encoding, and Mask Pattern Selection modules.


## Directory Structure

```
/foundation/arkui/qrcode
├── interfaces/kits/qrcode_generator.h    # QR Code Generator public interface
├── interfaces/innerkits/                 # QR Code Generator internal header files
│       ├── qrcode_inner.h                # Internal data structure definition
│       ├── qrcode_version.h              # Version Selection
│       ├── qrcode_stream.h               # Code Assembly
│       ├── qrcode_rscode.h               # RS Encoding
│       ├── qrcode_mask.h                 # Mask Pattern Selection
│       ├── qrcode_item.h                 # Data segmentation
│       └── qrcode_list.h                 # Linked list operations
├── frameworks/                           # QR Code core implementation
│       ├── qrcode_generator.cpp          # Generator main entry
│       ├── qrcode_version.cpp            # Version Selection
│       ├── qrcode_string.cpp             # String parsing
│       ├── qrcode_stream.cpp             # Code Assembly
│       ├── qrcode_rscode.cpp             # RS Encoding
│       ├── qrcode_mask.cpp               # Mask Pattern Selection
│       └── qrcode_item.cpp               # Data segmentation
├── test/unittest/common/                 # Unit test code
│       ├── qrcode_generator_test.cpp
│       ├── qrcode_version_test.cpp
│       ├── qrcode_stream_test.cpp
│       ├── qrcode_item_test.cpp
│       ├── qrcode_mask_test.cpp
│       └── qrcode_rscode_test.cpp
└── patches/
    └── patches.json
```

## Constraints

- The input text length is limited by version and error correction level. The actual usable length is calculated at runtime. For example: With H-level error correction, the input character code must not exceed the maximum data capacity of Version 40 (approximately 1852 bytes). QR codes cannot be generated if this length is exceeded.
- After inputting character code stream, the QR Code Generator automatically selects the minimum Version that can contain the data. When Version is 40, the maximum size is 177×177 pixels (px).
- Only square QR code output is supported. Other shapes (such as rectangles, circles, etc.) are not supported.
- When using Byte mode, UTF-8 encoding is used by default.

## Building

Use the following command to build for different target platforms:

**Build qrcode component for 32-bit ARM system**

```bash
./build.sh --product-name {product_name} --ccache --build-target qrcodegenerator
```

> **Note:**
> `{product_name}` is the currently supported platform name, for example `rk3568`.

## Description

The QR Code Generator provides public interfaces for system components or applications to generate QR codes.

### Data Structure Description

#### QrcodeImage

`QrcodeImage` is the output structure of QR code generation, defined as follows:

```c
typedef struct {
    int32_t version;
    uint32_t width;
    uint8_t *data;
} QrcodeImage;
```

| Field | Type | Description |
|-------|------|-------------|
| version | int32_t | QR code version actually used，The value ranges from 1 to 40. (auto-selected based on input data) |
| width | uint32_t | Width of the generated QR code image in pixels（px） |
| data | uint8_t* | Pointer to the image pixel data buffer |

**Notes:**

- The `data` buffer size equals `width * width` bytes
- Each byte represents a pixel value (0 for white, non-zero for black)
- Memory allocated in `data` must be freed by calling `QrcodeImageFree()`

### Interface Description

<table><thead align="left"><tr id="row1111111111111"><th class="cellrowborder" valign="top" width="50.22%" id="mcps1.1.3.1.1"><p id="p1111111111111"><a name="p1111111111111"></a><a name="p1111111111111"></a>Interface Name</p>
</th>
<th class="cellrowborder" valign="top" width="49.78%" id="mcps1.1.3.1.2"><p id="p2222222222222"><a name="p2222222222222"></a><a name="p2222222222222"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2222222222222"><td class="cellrowborder" valign="top" width="50.22%" headers="mcps1.1.3.1.1 "><p id="p3333333333333"><a name="p3333333333333"></a><a name="p3333333333333"></a>QrcodeImage *QrcodeImageEncodeString(const char *text, QRCODE_ECC qrEcc)</p>
</td>
<td class="cellrowborder" valign="top" width="49.78%" headers="mcps1.1.3.1.2 "><p id="p4444444444444"><a name="p4444444444444"></a><a name="p4444444444444"></a>Encodes a string into QR code data</p>
</td>
</tr>
<tr id="row3333333333333"><td class="cellrowborder" valign="top" width="50.22%" headers="mcps1.1.3.1.1 "><p id="p5555555555555"><a name="p5555555555555"></a><a name="p5555555555555"></a>void QrcodeImageFree(QrcodeImage *qrImage)</p>
</td>
<td class="cellrowborder" valign="top" width="49.78%" headers="mcps1.1.3.1.2 "><p id="p6666666666666"><a name="p6666666666666"></a><a name="p6666666666666"></a>Frees QR code data memory</p>
</td>
</tr>
<tr id="row4444444444444"><td class="cellrowborder" valign="top" width="50.22%" headers="mcps1.1.3.1.1 "><p id="p7777777777777"><a name="p7777777777777"></a><a name="p7777777777777"></a>void QrcodeMemInitHooks(const QrcodeMemHooks *hooks)</p>
</td>
<td class="cellrowborder" valign="top" width="49.78%" headers="mcps1.1.3.1.2 "><p id="p8888888888888"><a name="p8888888888888"></a><a name="p8888888888888"></a>Initializes custom memory allocation hooks</p>
</td>
</tr>
</tbody>
</table>

#### Error Correction Level Description

<table><thead align="left"><tr id="row5555555555555"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.3.2.1"><p id="p1111111111112"><a name="p1111111111112"></a><a name="p1111111111112"></a>Level</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.3.2.2"><p id="p2222222222223"><a name="p2222222222223"></a><a name="p2222222222223"></a>Enum Value</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.3.2.3"><p id="p3333333333334"><a name="p3333333333334"></a><a name="p3333333333334"></a>Error Correction Capability</p>
</th>
<th class="cellrowborder" valign="top" width="40%" id="mcps1.1.3.2.4"><p id="p4444444444445"><a name="p4444444444445"></a><a name="p4444444444445"></a>Applicable Scenario</p>
</th>
</tr>
</thead>
<tbody><tr id="row6666666666666"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.3.2.1 "><p id="p7777777777778"><a name="p7777777777778"></a><a name="p7777777777778"></a>M (Medium)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.3.2.2 "><p id="p8888888888889"><a name="p8888888888889"></a><a name="p8888888888889"></a>QRCODE_ECC_MEDIUM</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.3.2.3 "><p id="p9999999999999"><a name="p9999999999999"></a><a name="p9999999999999"></a>Approximately 15%</p>
</td>
<td class="cellrowborder" valign="top" width="40%" headers="mcps1.1.3.2.4 "><p id="p1010101010101"><a name="p1010101010101"></a><a name="p1010101010101"></a>General scenarios, balancing capacity and error correction</p>
</td>
</tr>
<tr id="row7777777777777"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.3.2.1 "><p id="p1111111111113"><a name="p1111111111113"></a><a name="p1111111111113"></a>H (High)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.3.2.2 "><p id="p2222222222224"><a name="p2222222222224"></a><a name="p2222222222224"></a>QRCODE_ECC_HIGH</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.3.2.3 "><p id="p3333333333335"><a name="p3333333333335"></a><a name="p3333333333335"></a>Approximately 30%</p>
</td>
<td class="cellrowborder" valign="top" width="40%" headers="mcps1.1.3.2.4 "><p id="p4444444444446"><a name="p4444444444446"></a><a name="p4444444444446"></a>High reliability requirement scenarios (industrial, medical, etc.)</p>
</td>
</tr>
</tbody>
</table>

**Note:**
- Higher error correction levels allow recovery of larger proportions of damage, but the available data capacity is reduced accordingly.
- The error correction algorithm is implemented using Reed-Solomon (RS) codes.


### Usage

Call the QR Code Generator interface to encode text into a QR code image:

```
QrcodeImage *qrImage = QrcodeImageEncodeString("https://openharmony.cn", QRCODE_ECC_MEDIUM);
if (qrImage != NULL) {
    // Use qrImage->data to generate QR code image
    // qrImage->width is the image width
    // qrImage->version is the actual QR code version used
    // qrImage data must be freed explicitly after use
    QrcodeImageFree(qrImage);
}
```

For custom memory allocation:

```
QrcodeMemHooks hooks = {
    .mallocFunc = myMalloc,
    .freeFunc = myFree
};
QrcodeMemInitHooks(&hooks);
```

## Repositories Involved

- [third_party_bounds_checking_function](https://gitcode.com/openharmony/third_party_bounds_checking_function)
- [arkui_ui_lite](https://gitcode.com/openharmony/arkui_ui_lite)
- [arkui_ace_engine](https://gitcode.com/openharmony/arkui_ace_engine)