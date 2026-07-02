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

#include "interfaces/innerkits/qrcode_rscode.h"
#include <gtest/gtest.h>
#include <cstring>

using namespace testing::ext;

class QrcodeRscodeTest : public testing::Test {
public:
    static void SetUpTestCase(void);
    static void TearDownTestCase(void);
    void SetUp();
    void TearDown();
};

void QrcodeRscodeTest::SetUpTestCase(void) {}

void QrcodeRscodeTest::TearDownTestCase(void) {}

void QrcodeRscodeTest::SetUp(void) {}

void QrcodeRscodeTest::TearDown(void) {}

/**
 * @tc.name: qrcode_rscode_init_001
 * @tc.desc: Verify initializing Reed-Solomon code.
 * @tc.type: FUNC
 * @tc.require: issueI000006
 */
HWTEST_F(QrcodeRscodeTest, qrcode_rscode_init_001, TestSize.Level1)
{
    ReedSolomonCodeData codeData = {8, 0x11d, 1, 1, 10, 0};
    ReedSolomonCode *rsCode = ReedSolomonCodeInit(codeData);
    EXPECT_NE(rsCode, nullptr);
    if (rsCode != nullptr) {
        ReedSolomonCodeFree(rsCode);
    }
}

/**
 * @tc.name: qrcode_rscode_encode_002
 * @tc.desc: Verify encoding with Reed-Solomon code.
 * @tc.type: FUNC
 * @tc.require: issueI000006
 */
HWTEST_F(QrcodeRscodeTest, qrcode_rscode_encode_002, TestSize.Level1)
{
    ReedSolomonCodeData codeData = {8, 0x11d, 1, 1, 10, 0};
    ReedSolomonCode *rsCode = ReedSolomonCodeInit(codeData);
    EXPECT_NE(rsCode, nullptr);
    if (rsCode != nullptr) {
        uint8_t data[10] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A};
        uint8_t parity[10] = {0};
        ReedSolomonCodeEncode(rsCode, data, parity);
        ReedSolomonCodeFree(rsCode);
    }
}

/**
 * @tc.name: qrcode_rscode_free_null_003
 * @tc.desc: Verify freeing null Reed-Solomon code.
 * @tc.type: FUNC
 * @tc.require: issueI000006
 */
HWTEST_F(QrcodeRscodeTest, qrcode_rscode_free_null_003, TestSize.Level1)
{
    ReedSolomonCodeFree(nullptr);
}

/**
 * @tc.name: qrcode_rscode_free_cache_004
 * @tc.desc: Verify freeing Reed-Solomon cache.
 * @tc.type: FUNC
 * @tc.require: issueI000006
 */
HWTEST_F(QrcodeRscodeTest, qrcode_rscode_free_cache_004, TestSize.Level1)
{
    ReedSolomonCodeFreeCache();
}

/**
 * @tc.name: qrcode_rscode_init_different_params_005
 * @tc.desc: Verify initializing with different parameters.
 * @tc.type: FUNC
 * @tc.require: issueI000006
 */
HWTEST_F(QrcodeRscodeTest, qrcode_rscode_init_different_params_005, TestSize.Level1)
{
    ReedSolomonCodeData codeData = {8, 0x11d, 0, 1, 16, 0};
    ReedSolomonCode *rsCode = ReedSolomonCodeInit(codeData);
    EXPECT_NE(rsCode, nullptr);
    if (rsCode != nullptr) {
        ReedSolomonCodeFree(rsCode);
    }
}

/**
 * @tc.name: qrcode_rscode_encode_null_data_006
 * @tc.desc: Verify encoding with null data pointer.
 * @tc.type: FUNC
 * @tc.require: issueI000006
 */
HWTEST_F(QrcodeRscodeTest, qrcode_rscode_encode_null_data_006, TestSize.Level1)
{
    ReedSolomonCodeData codeData = {8, 0x11d, 1, 1, 10, 0};
    ReedSolomonCode *rsCode = ReedSolomonCodeInit(codeData);
    EXPECT_NE(rsCode, nullptr);
    if (rsCode != nullptr) {
        uint8_t parity[10] = {0};
        ReedSolomonCodeEncode(rsCode, nullptr, parity);
        ReedSolomonCodeFree(rsCode);
    }
}

/**
 * @tc.name: qrcode_rscode_encode_null_parity_007
 * @tc.desc: Verify encoding with null parity pointer.
 * @tc.type: FUNC
 * @tc.require: issueI000006
 */
HWTEST_F(QrcodeRscodeTest, qrcode_rscode_encode_null_parity_007, TestSize.Level1)
{
    ReedSolomonCodeData codeData = {8, 0x11d, 1, 1, 10, 0};
    ReedSolomonCode *rsCode = ReedSolomonCodeInit(codeData);
    EXPECT_NE(rsCode, nullptr);
    if (rsCode != nullptr) {
        uint8_t data[10] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A};
        ReedSolomonCodeEncode(rsCode, data, nullptr);
        ReedSolomonCodeFree(rsCode);
    }
}