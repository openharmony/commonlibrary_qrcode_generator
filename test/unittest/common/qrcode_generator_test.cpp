/*
 * Copyright (c) 2022-2026 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "interfaces/kits/qrcode_generator.h"
#include "interfaces/innerkits/qrcode_version.h"
#include <gtest/gtest.h>
#include <cstring>

using namespace testing::ext;

class QrcodeGeneratorTest : public testing::Test {
public:
    static void SetUpTestCase(void);
    static void TearDownTestCase(void);
    void SetUp();
    void TearDown();
};

void QrcodeGeneratorTest::SetUpTestCase(void) {}

void QrcodeGeneratorTest::TearDownTestCase(void) {}

void QrcodeGeneratorTest::SetUp(void) {}

void QrcodeGeneratorTest::TearDown(void) {}

/**
 * @tc.name: qrcode_encode_empty_string_001
 * @tc.desc: Verify encoding empty string.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_encode_empty_string_001, TestSize.Level1)
{
    QrcodeImage *qrImage = QrcodeImageEncodeString("", QRCODE_ECC_MEDIUM);
    EXPECT_EQ(qrImage, nullptr);
}

/**
 * @tc.name: qrcode_encode_simple_text_002
 * @tc.desc: Verify encoding simple text.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_encode_simple_text_002, TestSize.Level1)
{
    const char *text = "Hello";
    QrcodeImage *qrImage = QrcodeImageEncodeString(text, QRCODE_ECC_MEDIUM);
    EXPECT_NE(qrImage, nullptr);
    if (qrImage != nullptr) {
        EXPECT_GT(qrImage->width, 0);
        EXPECT_NE(qrImage->data, nullptr);
        QrcodeImageFree(qrImage);
    }
}

/**
 * @tc.name: qrcode_encode_numeric_text_003
 * @tc.desc: Verify encoding numeric text.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_encode_numeric_text_003, TestSize.Level1)
{
    const char *text = "1234567890";
    QrcodeImage *qrImage = QrcodeImageEncodeString(text, QRCODE_ECC_MEDIUM);
    EXPECT_NE(qrImage, nullptr);
    if (qrImage != nullptr) {
        EXPECT_GT(qrImage->width, 0);
        EXPECT_NE(qrImage->data, nullptr);
        QrcodeImageFree(qrImage);
    }
}

/**
 * @tc.name: qrcode_encode_alphanumeric_text_004
 * @tc.desc: Verify encoding alphanumeric text.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_encode_alphanumeric_text_004, TestSize.Level1)
{
    const char *text = "ABC123XYZ";
    QrcodeImage *qrImage = QrcodeImageEncodeString(text, QRCODE_ECC_MEDIUM);
    EXPECT_NE(qrImage, nullptr);
    if (qrImage != nullptr) {
        EXPECT_GT(qrImage->width, 0);
        EXPECT_NE(qrImage->data, nullptr);
        QrcodeImageFree(qrImage);
    }
}

/**
 * @tc.name: qrcode_encode_long_text_005
 * @tc.desc: Verify encoding long text.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_encode_long_text_005, TestSize.Level1)
{
    const char *text = "This is a long text for testing QR code generation with more characters";
    QrcodeImage *qrImage = QrcodeImageEncodeString(text, QRCODE_ECC_MEDIUM);
    EXPECT_NE(qrImage, nullptr);
    if (qrImage != nullptr) {
        EXPECT_GT(qrImage->width, 0);
        EXPECT_NE(qrImage->data, nullptr);
        QrcodeImageFree(qrImage);
    }
}

/**
 * @tc.name: qrcode_encode_ecc_medium_006
 * @tc.desc: Verify encoding with ECC_MEDIUM.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_encode_ecc_medium_006, TestSize.Level1)
{
    const char *text = "Test";
    QrcodeImage *qrImage = QrcodeImageEncodeString(text, QRCODE_ECC_MEDIUM);
    EXPECT_NE(qrImage, nullptr);
    if (qrImage != nullptr) {
        EXPECT_GT(qrImage->width, 0);
        EXPECT_NE(qrImage->data, nullptr);
        QrcodeImageFree(qrImage);
    }
}

/**
 * @tc.name: qrcode_encode_ecc_high_007
 * @tc.desc: Verify encoding with ECC_HIGH.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_encode_ecc_high_007, TestSize.Level1)
{
    const char *text = "Test";
    QrcodeImage *qrImage = QrcodeImageEncodeString(text, QRCODE_ECC_HIGH);
    EXPECT_NE(qrImage, nullptr);
    if (qrImage != nullptr) {
        EXPECT_GT(qrImage->width, 0);
        EXPECT_NE(qrImage->data, nullptr);
        QrcodeImageFree(qrImage);
    }
}

/**
 * @tc.name: qrcode_free_null_image_008
 * @tc.desc: Verify freeing null image.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_free_null_image_008, TestSize.Level1)
{
    QrcodeImageFree(nullptr);
}

/**
 * @tc.name: qrcode_free_valid_image_009
 * @tc.desc: Verify freeing valid image.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_free_valid_image_009, TestSize.Level1)
{
    const char *text = "Test";
    QrcodeImage *qrImage = QrcodeImageEncodeString(text, QRCODE_ECC_MEDIUM);
    EXPECT_NE(qrImage, nullptr);
    if (qrImage != nullptr) {
        QrcodeImageFree(qrImage);
    }
}

/**
 * @tc.name: qrcode_encode_special_chars_010
 * @tc.desc: Verify encoding with special characters.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_encode_special_chars_010, TestSize.Level1)
{
    const char *text = "Hello@World.com";
    QrcodeImage *qrImage = QrcodeImageEncodeString(text, QRCODE_ECC_MEDIUM);
    EXPECT_NE(qrImage, nullptr);
    if (qrImage != nullptr) {
        EXPECT_GT(qrImage->width, 0);
        EXPECT_NE(qrImage->data, nullptr);
        QrcodeImageFree(qrImage);
    }
}

/**
 * @tc.name: qrcode_encode_chinese_chars_011
 * @tc.desc: Verify encoding with Chinese characters.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_encode_chinese_chars_011, TestSize.Level1)
{
    const char *text = "测试";
    QrcodeImage *qrImage = QrcodeImageEncodeString(text, QRCODE_ECC_MEDIUM);
    EXPECT_NE(qrImage, nullptr);
    if (qrImage != nullptr) {
        EXPECT_GT(qrImage->width, 0);
        EXPECT_NE(qrImage->data, nullptr);
        QrcodeImageFree(qrImage);
    }
}

/**
 * @tc.name: qrcode_encode_url_012
 * @tc.desc: Verify encoding URL.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_encode_url_012, TestSize.Level1)
{
    const char *text = "https://www.example.com";
    QrcodeImage *qrImage = QrcodeImageEncodeString(text, QRCODE_ECC_MEDIUM);
    EXPECT_NE(qrImage, nullptr);
    if (qrImage != nullptr) {
        EXPECT_GT(qrImage->width, 0);
        EXPECT_NE(qrImage->data, nullptr);
        QrcodeImageFree(qrImage);
    }
}

/**
 * @tc.name: qrcode_encode_version_check_013
 * @tc.desc: Verify QR code version is valid.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_encode_version_check_013, TestSize.Level1)
{
    const char *text = "Test";
    QrcodeImage *qrImage = QrcodeImageEncodeString(text, QRCODE_ECC_MEDIUM);
    EXPECT_NE(qrImage, nullptr);
    if (qrImage != nullptr) {
        EXPECT_GE(qrImage->version, 1);
        EXPECT_LE(qrImage->version, QRCODE_VERSION_MAX);
        QrcodeImageFree(qrImage);
    }
}

/**
 * @tc.name: qrcode_encode_width_check_014
 * @tc.desc: Verify QR code width is valid.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_encode_width_check_014, TestSize.Level1)
{
    const char *text = "Test";
    QrcodeImage *qrImage = QrcodeImageEncodeString(text, QRCODE_ECC_MEDIUM);
    EXPECT_NE(qrImage, nullptr);
    if (qrImage != nullptr) {
        EXPECT_GT(qrImage->width, 0);
        EXPECT_LE(qrImage->width, QRCODE_VERSION_WIDTH_MAX);
        QrcodeImageFree(qrImage);
    }
}

/**
 * @tc.name: qrcode_encode_data_not_null_015
 * @tc.desc: Verify QR code data is not null.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_encode_data_not_null_015, TestSize.Level1)
{
    const char *text = "Test";
    QrcodeImage *qrImage = QrcodeImageEncodeString(text, QRCODE_ECC_MEDIUM);
    EXPECT_NE(qrImage, nullptr);
    if (qrImage != nullptr) {
        EXPECT_NE(qrImage->data, nullptr);
        QrcodeImageFree(qrImage);
    }
}

/**
 * @tc.name: qrcode_mem_hooks_null_016
 * @tc.desc: Verify memory hooks with null pointer.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_mem_hooks_null_016, TestSize.Level1)
{
    QrcodeMemInitHooks(nullptr);
}

/**
 * @tc.name: qrcode_mem_hooks_invalid_017
 * @tc.desc: Verify memory hooks with invalid hooks.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_mem_hooks_invalid_017, TestSize.Level1)
{
    QrcodeMemHooks hooks = {nullptr, nullptr};
    QrcodeMemInitHooks(&hooks);
}

/**
 * @tc.name: qrcode_encode_multiple_times_018
 * @tc.desc: Verify encoding multiple times.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_encode_multiple_times_018, TestSize.Level1)
{
    const char *text = "Test";
    QrcodeImage *qrImage1 = QrcodeImageEncodeString(text, QRCODE_ECC_MEDIUM);
    EXPECT_NE(qrImage1, nullptr);

    QrcodeImage *qrImage2 = QrcodeImageEncodeString(text, QRCODE_ECC_HIGH);
    EXPECT_NE(qrImage2, nullptr);

    if (qrImage1 != nullptr) {
        QrcodeImageFree(qrImage1);
    }
    if (qrImage2 != nullptr) {
        QrcodeImageFree(qrImage2);
    }
}

/**
 * @tc.name: qrcode_encode_very_long_text_019
 * @tc.desc: Verify encoding very long text.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_encode_very_long_text_019, TestSize.Level1)
{
    const char *text =
        "This is a very long text for testing QR code generation with many characters to verify the functionality of "
        "the QR code generator library. It should handle long texts properly and generate valid QR codes.";
    QrcodeImage *qrImage = QrcodeImageEncodeString(text, QRCODE_ECC_MEDIUM);
    EXPECT_NE(qrImage, nullptr);
    if (qrImage != nullptr) {
        EXPECT_GT(qrImage->width, 0);
        EXPECT_NE(qrImage->data, nullptr);
        QrcodeImageFree(qrImage);
    }
}

/**
 * @tc.name: qrcode_encode_space_text_020
 * @tc.desc: Verify encoding text with spaces.
 * @tc.type: FUNC
 * @tc.require: issueI000001
 */
HWTEST_F(QrcodeGeneratorTest, qrcode_encode_space_text_020, TestSize.Level1)
{
    const char *text = "Hello World Test";
    QrcodeImage *qrImage = QrcodeImageEncodeString(text, QRCODE_ECC_MEDIUM);
    EXPECT_NE(qrImage, nullptr);
    if (qrImage != nullptr) {
        EXPECT_GT(qrImage->width, 0);
        EXPECT_NE(qrImage->data, nullptr);
        QrcodeImageFree(qrImage);
    }
}