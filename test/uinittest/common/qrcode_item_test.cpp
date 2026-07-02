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

#include "interfaces/innerkits/qrcode_item.h"
#include <gtest/gtest.h>
#include <cstring>

using namespace testing::ext;

class QrcodeItemTest : public testing::Test {
public:
    static void SetUpTestCase(void);
    static void TearDownTestCase(void);
    void SetUp();
    void TearDown();
};

void QrcodeItemTest::SetUpTestCase(void) {}

void QrcodeItemTest::TearDownTestCase(void) {}

void QrcodeItemTest::SetUp(void) {}

void QrcodeItemTest::TearDown(void) {}

/**
 * @tc.name: qrcode_item_list_new_001
 * @tc.desc: Verify creating new item list.
 * @tc.type: FUNC
 * @tc.require: issueI000003
 */
HWTEST_F(QrcodeItemTest, qrcode_item_list_new_001, TestSize.Level1)
{
    QrcodeItemList *list = QrcodeItemListNew();
    EXPECT_NE(list, nullptr);
    if (list != nullptr) {
        QrcodeItemListFree(list);
    }
}

/**
 * @tc.name: qrcode_item_list_add_numeric_002
 * @tc.desc: Verify adding numeric item to list.
 * @tc.type: FUNC
 * @tc.require: issueI000003
 */
HWTEST_F(QrcodeItemTest, qrcode_item_list_add_numeric_002, TestSize.Level1)
{
    QrcodeItemList *list = QrcodeItemListNew();
    EXPECT_NE(list, nullptr);
    if (list != nullptr) {
        const uint8_t data[] = "12345";
        int32_t ret = QrcodeItemListAdd(list, QRCODE_MODE_NUM, 5, data);
        EXPECT_EQ(ret, 0);
        QrcodeItemListFree(list);
    }
}

/**
 * @tc.name: qrcode_item_list_add_alphanumeric_003
 * @tc.desc: Verify adding alphanumeric item to list.
 * @tc.type: FUNC
 * @tc.require: issueI000003
 */
HWTEST_F(QrcodeItemTest, qrcode_item_list_add_alphanumeric_003, TestSize.Level1)
{
    QrcodeItemList *list = QrcodeItemListNew();
    EXPECT_NE(list, nullptr);
    if (list != nullptr) {
        const uint8_t data[] = "ABC123";
        int32_t ret = QrcodeItemListAdd(list, QRCODE_MODE_AN, 6, data);
        EXPECT_EQ(ret, 0);
        QrcodeItemListFree(list);
    }
}

/**
 * @tc.name: qrcode_item_list_add_byte_004
 * @tc.desc: Verify adding byte item to list.
 * @tc.type: FUNC
 * @tc.require: issueI000003
 */
HWTEST_F(QrcodeItemTest, qrcode_item_list_add_byte_004, TestSize.Level1)
{
    QrcodeItemList *list = QrcodeItemListNew();
    EXPECT_NE(list, nullptr);
    if (list != nullptr) {
        const uint8_t data[] = "Hello";
        int32_t ret = QrcodeItemListAdd(list, QRCODE_MODE_8, 5, data);
        EXPECT_EQ(ret, 0);
        QrcodeItemListFree(list);
    }
}

/**
 * @tc.name: qrcode_item_list_free_null_005
 * @tc.desc: Verify freeing null item list.
 * @tc.type: FUNC
 * @tc.require: issueI000003
 */
HWTEST_F(QrcodeItemTest, qrcode_item_list_free_null_005, TestSize.Level1)
{
    QrcodeItemListFree(nullptr);
}

/**
 * @tc.name: qrcode_item_check_numeric_006
 * @tc.desc: Verify checking numeric item.
 * @tc.type: FUNC
 * @tc.require: issueI000003
 */
HWTEST_F(QrcodeItemTest, qrcode_item_check_numeric_006, TestSize.Level1)
{
    const uint8_t data[] = "12345";
    int32_t ret = QrcodeItemCheck(QRCODE_MODE_NUM, 5, data);
    EXPECT_EQ(ret, 0);
}

/**
 * @tc.name: qrcode_item_check_alphanumeric_007
 * @tc.desc: Verify checking alphanumeric item.
 * @tc.type: FUNC
 * @tc.require: issueI000003
 */
HWTEST_F(QrcodeItemTest, qrcode_item_check_alphanumeric_007, TestSize.Level1)
{
    const uint8_t data[] = "ABC123";
    int32_t ret = QrcodeItemCheck(QRCODE_MODE_AN, 6, data);
    EXPECT_EQ(ret, 0);
}

/**
 * @tc.name: qrcode_item_check_byte_008
 * @tc.desc: Verify checking byte item.
 * @tc.type: FUNC
 * @tc.require: issueI000003
 */
HWTEST_F(QrcodeItemTest, qrcode_item_check_byte_008, TestSize.Level1)
{
    const uint8_t data[] = "Hello";
    int32_t ret = QrcodeItemCheck(QRCODE_MODE_8, 5, data);
    EXPECT_EQ(ret, 0);
}

/**
 * @tc.name: qrcode_item_list_get_byte_stream_009
 * @tc.desc: Verify getting byte stream from item list.
 * @tc.type: FUNC
 * @tc.require: issueI000003
 */
HWTEST_F(QrcodeItemTest, qrcode_item_list_get_byte_stream_009, TestSize.Level1)
{
    QrcodeItemList *list = QrcodeItemListNew();
    EXPECT_NE(list, nullptr);
    if (list != nullptr) {
        const uint8_t data[] = "12345";
        QrcodeItemListAdd(list, QRCODE_MODE_NUM, 5, data);
        uint8_t *stream = QrcodeItemListGetByteStream(list);
        EXPECT_NE(stream, nullptr);
        if (stream != nullptr) {
            QrcodeFree(stream);
        }
        QrcodeItemListFree(list);
    }
}

/**
 * @tc.name: qrcode_estimate_num_010
 * @tc.desc: Verify estimating numeric size.
 * @tc.type: FUNC
 * @tc.require: issueI000003
 */
HWTEST_F(QrcodeItemTest, qrcode_estimate_num_010, TestSize.Level1)
{
    int32_t size = QrcodeEstimateNum(10);
    EXPECT_GT(size, 0);
}

/**
 * @tc.name: qrcode_estimate_alphabet_011
 * @tc.desc: Verify estimating alphanumeric size.
 * @tc.type: FUNC
 * @tc.require: issueI000003
 */
HWTEST_F(QrcodeItemTest, qrcode_estimate_alphabet_011, TestSize.Level1)
{
    int32_t size = QrcodeEstimateAlphaBet(10);
    EXPECT_GT(size, 0);
}

/**
 * @tc.name: qrcode_estimate_8_012
 * @tc.desc: Verify estimating byte size.
 * @tc.type: FUNC
 * @tc.require: issueI000003
 */
HWTEST_F(QrcodeItemTest, qrcode_estimate_8_012, TestSize.Level1)
{
    int32_t size = QrcodeEstimate8(10);
    EXPECT_GT(size, 0);
}

/**
 * @tc.name: qrcode_look_at_table_013
 * @tc.desc: Verify looking up character in table.
 * @tc.type: FUNC
 * @tc.require: issueI000003
 */
HWTEST_F(QrcodeItemTest, qrcode_look_at_table_013, TestSize.Level1)
{
    int32_t ret = QrcodeLookAtTable('A');
    EXPECT_GE(ret, 0);
}

/**
 * @tc.name: qrcode_is_valid_mode_014
 * @tc.desc: Verify checking valid mode.
 * @tc.type: FUNC
 * @tc.require: issueI000003
 */
HWTEST_F(QrcodeItemTest, qrcode_is_valid_mode_014, TestSize.Level1)
{
    bool valid = QrcodeIsValidMode(QRCODE_MODE_NUM);
    EXPECT_TRUE(valid);
}

/**
 * @tc.name: qrcode_is_valid_mode_invalid_015
 * @tc.desc: Verify checking invalid mode.
 * @tc.type: FUNC
 * @tc.require: issueI000003
 */
HWTEST_F(QrcodeItemTest, qrcode_is_valid_mode_invalid_015, TestSize.Level1)
{
    bool valid = QrcodeIsValidMode(QRCODE_MODE_NUL);
    EXPECT_FALSE(valid);
}

/**
 * @tc.name: qrcode_item_list_add_multiple_016
 * @tc.desc: Verify adding multiple items to list.
 * @tc.type: FUNC
 * @tc.require: issueI000003
 */
HWTEST_F(QrcodeItemTest, qrcode_item_list_add_multiple_016, TestSize.Level1)
{
    QrcodeItemList *list = QrcodeItemListNew();
    EXPECT_NE(list, nullptr);
    if (list != nullptr) {
        const uint8_t data1[] = "12345";
        const uint8_t data2[] = "ABC";
        QrcodeItemListAdd(list, QRCODE_MODE_NUM, 5, data1);
        QrcodeItemListAdd(list, QRCODE_MODE_AN, 3, data2);
        uint8_t *stream = QrcodeItemListGetByteStream(list);
        EXPECT_NE(stream, nullptr);
        if (stream != nullptr) {
            QrcodeFree(stream);
        }
        QrcodeItemListFree(list);
    }
}

/**
 * @tc.name: qrcode_item_check_invalid_numeric_017
 * @tc.desc: Verify checking invalid numeric item.
 * @tc.type: FUNC
 * @tc.require: issueI000003
 */
HWTEST_F(QrcodeItemTest, qrcode_item_check_invalid_numeric_017, TestSize.Level1)
{
    const uint8_t data[] = "12A45";
    int32_t ret = QrcodeItemCheck(QRCODE_MODE_NUM, 5, data);
    EXPECT_NE(ret, 0);
}

/**
 * @tc.name: qrcode_item_check_invalid_alphanumeric_018
 * @tc.desc: Verify checking invalid alphanumeric item.
 * @tc.type: FUNC
 * @tc.require: issueI000003
 */
HWTEST_F(QrcodeItemTest, qrcode_item_check_invalid_alphanumeric_018, TestSize.Level1)
{
    const uint8_t data[] = "AB@12";
    int32_t ret = QrcodeItemCheck(QRCODE_MODE_AN, 5, data);
    EXPECT_NE(ret, 0);
}