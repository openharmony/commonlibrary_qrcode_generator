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

#include <gtest/gtest.h>
#include "qrcode_inner.h"
#include "qrcode_item.h"
#include "qrcode_stream.h"
#include "qrcode_version.h"
#include "qrcode_rscode.h"
#include "qrcode_generator.h"

using namespace testing;

// Test fixture for mock tests
class QrcodeMockTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

// Test 1: QrcodeImageEncodeMask with null list
TEST_F(QrcodeMockTest, qrcode_image_encode_mask_null_list)
{
    QrcodeImage *image = QrcodeImageEncodeMask(nullptr);
    EXPECT_EQ(image, nullptr);
}

// Test 2: QrcodeStrToItemList with null list
TEST_F(QrcodeMockTest, qrcode_str_to_item_list_null_list)
{
    int32_t ret = QrcodeStrToItemList("123", nullptr);
    EXPECT_LT(ret, 0);
}

// Test 3: QrcodeItemListGetByteStream with null list
TEST_F(QrcodeMockTest, qrcode_item_list_get_byte_stream_null_list)
{
    uint8_t *stream = QrcodeItemListGetByteStream(nullptr);
    EXPECT_EQ(stream, nullptr);
}

// Test 4: QrcodeItemListFree with null list
TEST_F(QrcodeMockTest, qrcode_item_list_free_null_list)
{
    QrcodeItemListFree(nullptr);
    // Should not crash
}

// Test 5: QrcodeStreamFree with null stream
TEST_F(QrcodeMockTest, qrcode_stream_free_null_stream)
{
    QrcodeStreamFree(nullptr);
    // Should not crash
}

// Test 6: QrcodeImageFree with null image
TEST_F(QrcodeMockTest, qrcode_image_free_null_image)
{
    QrcodeImageFree(nullptr);
    // Should not crash
}

// Test 7: Test version 7+ to cover version-specific code paths
TEST_F(QrcodeMockTest, qrcode_version_7_specific_paths)
{
    QrcodeItemList *list = QrcodeItemListNew();
    ASSERT_NE(list, nullptr);

    const uint8_t data[] = "123";
    QrcodeItemListAdd(list, QRCODE_MODE_NUM, 3, data);

    // Set version to 7 to trigger version-specific code paths
    list->version = 7;

    QrcodeImage *image = QrcodeImageEncodeMask(list);
    EXPECT_NE(image, nullptr);

    QrcodeImageFree(image);
    QrcodeItemListFree(list);
}

// Test 8: Test version 10 to cover more version-specific code paths
TEST_F(QrcodeMockTest, qrcode_version_10_specific_paths)
{
    QrcodeItemList *list = QrcodeItemListNew();
    ASSERT_NE(list, nullptr);

    const uint8_t data[] = "123";
    QrcodeItemListAdd(list, QRCODE_MODE_NUM, 3, data);

    // Set version to 10 to trigger version-specific code paths
    list->version = 10;

    QrcodeImage *image = QrcodeImageEncodeMask(list);
    EXPECT_NE(image, nullptr);

    QrcodeImageFree(image);
    QrcodeItemListFree(list);
}

// Test 9: Test max version to cover edge cases
TEST_F(QrcodeMockTest, qrcode_version_max_edge_cases)
{
    QrcodeItemList *list = QrcodeItemListNew();
    ASSERT_NE(list, nullptr);

    const uint8_t data[] = "123";
    QrcodeItemListAdd(list, QRCODE_MODE_NUM, 3, data);

    // Set version to max to trigger edge cases
    list->version = QRCODE_VERSION_MAX;

    QrcodeImage *image = QrcodeImageEncodeMask(list);
    EXPECT_NE(image, nullptr);

    QrcodeImageFree(image);
    QrcodeItemListFree(list);
}

// Test 10: Test QrcodeStreamAddBytes with null stream
TEST_F(QrcodeMockTest, qrcode_stream_add_bytes_null_stream)
{
    uint8_t data[] = {0x01, 0x02, 0x03};
    int32_t ret = QrcodeStreamAddBytes(nullptr, 3, data);
    EXPECT_LT(ret, 0);
}

// Test 11: Test QrcodeStreamAddNum with null stream
TEST_F(QrcodeMockTest, qrcode_stream_add_num_null_stream)
{
    int32_t ret = QrcodeStreamAddNum(nullptr, 123, 3);
    EXPECT_LT(ret, 0);
}

// Test 12: Test QrcodeStreamAddNum with zero bit count
TEST_F(QrcodeMockTest, qrcode_stream_add_num_zero_bits)
{
    QrcodeStream *stream = QrcodeStreamNew();
    ASSERT_NE(stream, nullptr);

    int32_t ret = QrcodeStreamAddNum(stream, 123, 0);
    EXPECT_EQ(ret, 0);  // Adding zero bits should succeed (no-op)

    QrcodeStreamFree(stream);
}

// Test 13: Test QrcodeVersionGetPattern with invalid version
TEST_F(QrcodeMockTest, qrcode_version_get_pattern_invalid_version)
{
    uint32_t pattern = QrcodeVersionGetPattern(-1);
    EXPECT_EQ(pattern, 0);
}

// Test 14: Test QrcodeVersionGetPattern with version > max
TEST_F(QrcodeMockTest, qrcode_version_get_pattern_exceed_max)
{
    uint32_t pattern = QrcodeVersionGetPattern(QRCODE_VERSION_MAX + 1);
    EXPECT_EQ(pattern, 0);
}

// Test 15: Test QrcodeVersionGetEccInfo with invalid version (void return)
TEST_F(QrcodeMockTest, qrcode_version_get_ecc_info_invalid_version)
{
    int32_t spec[5] = {0};
    QrcodeVersionGetEccInfo(-1, spec, 5);
    // Should not crash, spec should be unchanged
    EXPECT_EQ(spec[0], 0);
}

// Test 16: Test QrcodeVersionGetEccInfo with null spec (void return)
TEST_F(QrcodeMockTest, qrcode_version_get_ecc_info_null_spec)
{
    QrcodeVersionGetEccInfo(1, nullptr, 5);
    // Should not crash
}

// Test 17: Test QrcodeVersionGetEccInfo with insufficient spec size (void return)
TEST_F(QrcodeMockTest, qrcode_version_get_ecc_info_insufficient_size)
{
    int32_t spec[2] = {0};
    QrcodeVersionGetEccInfo(1, spec, 2);
    // Should not crash
}

// Test 18: Test QrcodeItemListAdd with null list
TEST_F(QrcodeMockTest, qrcode_item_list_add_null_list)
{
    const uint8_t data[] = "123";
    int32_t ret = QrcodeItemListAdd(nullptr, QRCODE_MODE_NUM, 3, data);
    EXPECT_LT(ret, 0);
}

// Test 19: Test QrcodeItemListAdd with null data
TEST_F(QrcodeMockTest, qrcode_item_list_add_null_data)
{
    QrcodeItemList *list = QrcodeItemListNew();
    ASSERT_NE(list, nullptr);

    int32_t ret = QrcodeItemListAdd(list, QRCODE_MODE_NUM, 3, nullptr);
    EXPECT_LT(ret, 0);

    QrcodeItemListFree(list);
}

// Test 20: Test QrcodeItemListAdd with zero size
TEST_F(QrcodeMockTest, qrcode_item_list_add_zero_size)
{
    QrcodeItemList *list = QrcodeItemListNew();
    ASSERT_NE(list, nullptr);

    const uint8_t data[] = "123";
    int32_t ret = QrcodeItemListAdd(list, QRCODE_MODE_NUM, 0, data);
    EXPECT_LT(ret, 0);

    QrcodeItemListFree(list);
}

// Test 21: Test QrcodeItemListAdd with invalid mode
TEST_F(QrcodeMockTest, qrcode_item_list_add_invalid_mode)
{
    QrcodeItemList *list = QrcodeItemListNew();
    ASSERT_NE(list, nullptr);

    const uint8_t data[] = "123";
    int32_t ret = QrcodeItemListAdd(list, QRCODE_MODE_NUL, 3, data);
    EXPECT_LT(ret, 0);

    QrcodeItemListFree(list);
}

// Test 22: Test QrcodeImageEncodeString with null text
TEST_F(QrcodeMockTest, qrcode_image_encode_string_null_text)
{
    QrcodeImage *image = QrcodeImageEncodeString(nullptr, QRCODE_ECC_MEDIUM);
    EXPECT_EQ(image, nullptr);
}

// Test 23: Test QrcodeImageEncodeString with empty text
TEST_F(QrcodeMockTest, qrcode_image_encode_string_empty_text)
{
    QrcodeImage *image = QrcodeImageEncodeString("", QRCODE_ECC_MEDIUM);
    EXPECT_EQ(image, nullptr);
}

// Test 24: Test QrcodeStreamAddNum with negative number
TEST_F(QrcodeMockTest, qrcode_stream_add_num_negative)
{
    QrcodeStream *stream = QrcodeStreamNew();
    ASSERT_NE(stream, nullptr);

    int32_t ret = QrcodeStreamAddNum(stream, -1, 3);
    EXPECT_EQ(ret, 0);  // Negative number is accepted

    QrcodeStreamFree(stream);
}

// Test 25: Test QrcodeItemCheck with invalid mode
TEST_F(QrcodeMockTest, qrcode_item_check_invalid_mode)
{
    int32_t ret = QrcodeItemCheck(QRCODE_MODE_NUL, 3, (const uint8_t*)"123");
    EXPECT_LT(ret, 0);
}

// Test 26: Test QrcodeItemCheck with null data
TEST_F(QrcodeMockTest, qrcode_item_check_null_data)
{
    int32_t ret = QrcodeItemCheck(QRCODE_MODE_NUM, 3, nullptr);
    EXPECT_LT(ret, 0);
}

// Test 27: Test QrcodeLookAtTable with invalid character
TEST_F(QrcodeMockTest, qrcode_look_at_table_invalid_char)
{
    int32_t ret = QrcodeLookAtTable(0xFF);
    EXPECT_LT(ret, 0);
}

// Test 28: Test QrcodeEstimateNum with negative size
TEST_F(QrcodeMockTest, qrcode_estimate_num_negative_size)
{
    int32_t ret = QrcodeEstimateNum(-1);
    EXPECT_EQ(ret, 0);  // Negative size returns 0
}

// Test 29: Test QrcodeEstimateAlphaBet with negative size
TEST_F(QrcodeMockTest, qrcode_estimate_alphabet_negative_size)
{
    int32_t ret = QrcodeEstimateAlphaBet(-1);
    EXPECT_EQ(ret, 6);  // Negative size returns 6
}

// Test 30: Test QrcodeEstimate8 with negative size
TEST_F(QrcodeMockTest, qrcode_estimate_8_negative_size)
{
    int32_t ret = QrcodeEstimate8(-1);
    EXPECT_LT(ret, 0);
}

// Test 31: Test QrcodeStreamAdd with null stream
TEST_F(QrcodeMockTest, qrcode_stream_add_null_stream)
{
    QrcodeStream *arg = QrcodeStreamNew();
    ASSERT_NE(arg, nullptr);

    int32_t ret = QrcodeStreamAdd(nullptr, arg);
    EXPECT_LT(ret, 0);

    QrcodeStreamFree(arg);
}

// Test 32: Test QrcodeStreamAdd with null arg
TEST_F(QrcodeMockTest, qrcode_stream_add_null_arg)
{
    QrcodeStream *stream = QrcodeStreamNew();
    ASSERT_NE(stream, nullptr);

    int32_t ret = QrcodeStreamAdd(stream, nullptr);
    EXPECT_LT(ret, 0);

    QrcodeStreamFree(stream);
}

// Test 33: Test QrcodeStreamAdd with self
TEST_F(QrcodeMockTest, qrcode_stream_add_self)
{
    QrcodeStream *stream = QrcodeStreamNew();
    ASSERT_NE(stream, nullptr);

    int32_t ret = QrcodeStreamAdd(stream, stream);
    EXPECT_EQ(ret, -1);  // Adding stream to itself should fail

    QrcodeStreamFree(stream);
}

// Test 34: Test QrcodeVersionGetWidth with invalid version
TEST_F(QrcodeMockTest, qrcode_version_get_width_invalid_version)
{
    int32_t width = QrcodeVersionGetWidth(-1);
    EXPECT_NE(width, 0);  // Invalid version returns some default value
}

// Test 35: Test QrcodeImageEncodeString with different ECC levels
TEST_F(QrcodeMockTest, qrcode_image_encode_string_different_ecc)
{
    QrcodeImage *imageM = QrcodeImageEncodeString("123", QRCODE_ECC_MEDIUM);
    EXPECT_NE(imageM, nullptr);
    QrcodeImageFree(imageM);

    QrcodeImage *imageH = QrcodeImageEncodeString("123", QRCODE_ECC_HIGH);
    EXPECT_NE(imageH, nullptr);
    QrcodeImageFree(imageH);
}

// Test 36: Test QrcodeStreamDupData with null stream
TEST_F(QrcodeMockTest, qrcode_stream_dup_data_null_stream)
{
    uint8_t *data = QrcodeStreamDupData(nullptr);
    EXPECT_EQ(data, nullptr);
}

// Test 37: Test QrcodeStreamClean with null stream
TEST_F(QrcodeMockTest, qrcode_stream_clean_null_stream)
{
    QrcodeStreamClean(nullptr);
    // Should not crash
}

// Test 38: Test QrcodeVersionGetDataLen with invalid version
TEST_F(QrcodeMockTest, qrcode_version_get_data_len_invalid_version)
{
    int32_t len = QrcodeVersionGetDataLen(-1);
    EXPECT_NE(len, 0);  // Invalid version returns some default value
}

// Test 39: Test QrcodeVersionGetEccLen with invalid version
TEST_F(QrcodeMockTest, qrcode_version_get_ecc_len_invalid_version)
{
    int32_t len = QrcodeVersionGetEccLen(-1);
    EXPECT_NE(len, 0);  // Invalid version returns some default value
}

// Test 40: Test QrcodeVersionGetMinVersion with invalid size
TEST_F(QrcodeMockTest, qrcode_version_get_min_version_invalid_size)
{
    int32_t version = QrcodeVersionGetMinVersion(-1);
    EXPECT_NE(version, 0);  // Invalid size returns version 1
}

// Test 41: Test QrcodeVersionGetRemainder with invalid version
TEST_F(QrcodeMockTest, qrcode_version_get_remainder_invalid_version)
{
    int32_t remainder = QrcodeVersionGetRemainder(-1);
    EXPECT_EQ(remainder, 0);
}

// Test 42: Test QrcodeVersionModeLength with invalid mode
TEST_F(QrcodeMockTest, qrcode_version_mode_length_invalid_mode)
{
    int32_t len = QrcodeVersionModeLength(QRCODE_MODE_NUL, 1);
    EXPECT_EQ(len, 0);
}

// Test 43: Test QrcodeVersionMaxWordsInMode with invalid version
TEST_F(QrcodeMockTest, qrcode_version_max_words_in_mode_invalid_version)
{
    int32_t words = QrcodeVersionMaxWordsInMode(-1, QRCODE_MODE_NUM);
    EXPECT_NE(words, 0);  // Invalid version returns some default value
}

// Test 44: Test QrcodeVersionNewData with invalid version
TEST_F(QrcodeMockTest, qrcode_version_new_data_invalid_version)
{
    uint8_t *data = QrcodeVersionNewData(-1);
    EXPECT_EQ(data, nullptr);
}

// Test 45: Test QrcodeVersionClearCache with invalid version
TEST_F(QrcodeMockTest, qrcode_version_clear_cache_invalid_version)
{
    QrcodeVersionClearCache(-1);
    // Should not crash
}

// Test 46: Test QrcodeVersionGetFormatInfo with invalid mask
TEST_F(QrcodeMockTest, qrcode_version_get_format_info_invalid_mask)
{
    int32_t info = QrcodeVersionGetFormatInfo(-1);
    EXPECT_EQ(info, 0);
}

// Test 47: Test QrcodeIsValidMode with invalid mode
TEST_F(QrcodeMockTest, qrcode_is_valid_mode_invalid_mode)
{
    bool valid = QrcodeIsValidMode(QRCODE_MODE_NUL);
    EXPECT_EQ(valid, false);
}

// Test 48: Test QrcodeImageEncodeString with very long text
TEST_F(QrcodeMockTest, qrcode_image_encode_string_long_text)
{
    // Create a long string that should still work
    std::string longText(100, 'A');
    QrcodeImage *image = QrcodeImageEncodeString(longText.c_str(), QRCODE_ECC_MEDIUM);
    EXPECT_NE(image, nullptr);
    QrcodeImageFree(image);
}

// Test 49: Test QrcodeStrToItemList with empty string
TEST_F(QrcodeMockTest, qrcode_str_to_item_list_empty_string)
{
    QrcodeItemList *list = QrcodeItemListNew();
    ASSERT_NE(list, nullptr);

    int32_t ret = QrcodeStrToItemList("", list);
    EXPECT_EQ(ret, 0);  // Empty string is accepted

    QrcodeItemListFree(list);
}

// Test 50: Test QrcodeStrToItemList with null string
TEST_F(QrcodeMockTest, qrcode_str_to_item_list_null_string)
{
    QrcodeItemList *list = QrcodeItemListNew();
    ASSERT_NE(list, nullptr);

    int32_t ret = QrcodeStrToItemList(nullptr, list);
    EXPECT_LT(ret, 0);

    QrcodeItemListFree(list);
}