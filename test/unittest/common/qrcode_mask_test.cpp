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

#include "interfaces/innerkits/qrcode_mask.h"
#include "interfaces/innerkits/qrcode_inner.h"
#include <gtest/gtest.h>
#include <cstring>

using namespace testing::ext;

class QrcodeMaskTest : public testing::Test {
public:
    static void SetUpTestCase(void);
    static void TearDownTestCase(void);
    void SetUp();
    void TearDown();
};

void QrcodeMaskTest::SetUpTestCase(void) {}

void QrcodeMaskTest::TearDownTestCase(void) {}

void QrcodeMaskTest::SetUp(void) {}

void QrcodeMaskTest::TearDown(void) {}

/**
 * @tc.name: qrcode_mask_find_mask_001
 * @tc.desc: Verify finding mask for small QR code.
 * @tc.type: FUNC
 * @tc.require: issueI000005
 */
HWTEST_F(QrcodeMaskTest, qrcode_mask_find_mask_001, TestSize.Level1)
{
    int32_t width = 21;
    uint8_t *data = (uint8_t *)QrcodeMalloc(width * width);
    EXPECT_NE(data, nullptr);
    if (data != nullptr) {
        (void)memset_s(data, width * width, 0, width * width);
        uint8_t *mask = QrcodeMaskFindMask(width, data);
        EXPECT_NE(mask, nullptr);
        if (mask != nullptr) {
            QrcodeFree(mask);
        }
        QrcodeFree(data);
    }
}

/**
 * @tc.name: qrcode_mask_find_mask_medium_002
 * @tc.desc: Verify finding mask for medium QR code.
 * @tc.type: FUNC
 * @tc.require: issueI000005
 */
HWTEST_F(QrcodeMaskTest, qrcode_mask_find_mask_medium_002, TestSize.Level1)
{
    int32_t width = 25;
    uint8_t *data = (uint8_t *)QrcodeMalloc(width * width);
    EXPECT_NE(data, nullptr);
    if (data != nullptr) {
        (void)memset_s(data, width * width, 0, width * width);
        uint8_t *mask = QrcodeMaskFindMask(width, data);
        EXPECT_NE(mask, nullptr);
        if (mask != nullptr) {
            QrcodeFree(mask);
        }
        QrcodeFree(data);
    }
}

/**
 * @tc.name: qrcode_mask_find_mask_large_003
 * @tc.desc: Verify finding mask for large QR code.
 * @tc.type: FUNC
 * @tc.require: issueI000005
 */
HWTEST_F(QrcodeMaskTest, qrcode_mask_find_mask_large_003, TestSize.Level1)
{
    int32_t width = 29;
    uint8_t *data = (uint8_t *)QrcodeMalloc(width * width);
    EXPECT_NE(data, nullptr);
    if (data != nullptr) {
        (void)memset_s(data, width * width, 0, width * width);
        uint8_t *mask = QrcodeMaskFindMask(width, data);
        EXPECT_NE(mask, nullptr);
        if (mask != nullptr) {
            QrcodeFree(mask);
        }
        QrcodeFree(data);
    }
}

/**
 * @tc.name: qrcode_mask_find_mask_null_data_004
 * @tc.desc: Verify finding mask with null data.
 * @tc.type: FUNC
 * @tc.require: issueI000005
 */
HWTEST_F(QrcodeMaskTest, qrcode_mask_find_mask_null_data_004, TestSize.Level1)
{
    uint8_t *mask = QrcodeMaskFindMask(21, nullptr);
    EXPECT_EQ(mask, nullptr);
}

/**
 * @tc.name: qrcode_mask_find_mask_zero_width_005
 * @tc.desc: Verify finding mask with zero width.
 * @tc.type: FUNC
 * @tc.require: issueI000005
 */
HWTEST_F(QrcodeMaskTest, qrcode_mask_find_mask_zero_width_005, TestSize.Level1)
{
    uint8_t *mask = QrcodeMaskFindMask(0, nullptr);
    EXPECT_EQ(mask, nullptr);
}