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

#include "interfaces/innerkits/qrcode_version.h"
#include <gtest/gtest.h>

using namespace testing::ext;

class QrcodeVersionTest : public testing::Test {
public:
    static void SetUpTestCase(void);
    static void TearDownTestCase(void);
    void SetUp();
    void TearDown();
};

void QrcodeVersionTest::SetUpTestCase(void) {}

void QrcodeVersionTest::TearDownTestCase(void) {}

void QrcodeVersionTest::SetUp(void) {}

void QrcodeVersionTest::TearDown(void) {}

/**
 * @tc.name: qrcode_version_get_data_len_001
 * @tc.desc: Verify getting data length for valid version.
 * @tc.type: FUNC
 * @tc.require: issueI000002
 */
HWTEST_F(QrcodeVersionTest, qrcode_version_get_data_len_001, TestSize.Level1)
{
    int32_t dataLen = QrcodeVersionGetDataLen(1);
    EXPECT_GT(dataLen, 0);
}

/**
 * @tc.name: qrcode_version_get_ecc_len_002
 * @tc.desc: Verify getting ECC length for valid version.
 * @tc.type: FUNC
 * @tc.require: issueI000002
 */
HWTEST_F(QrcodeVersionTest, qrcode_version_get_ecc_len_002, TestSize.Level1)
{
    int32_t eccLen = QrcodeVersionGetEccLen(1);
    EXPECT_GT(eccLen, 0);
}

/**
 * @tc.name: qrcode_version_get_width_003
 * @tc.desc: Verify getting width for valid version.
 * @tc.type: FUNC
 * @tc.require: issueI000002
 */
HWTEST_F(QrcodeVersionTest, qrcode_version_get_width_003, TestSize.Level1)
{
    int32_t width = QrcodeVersionGetWidth(1);
    EXPECT_GT(width, 0);
}

/**
 * @tc.name: qrcode_version_get_remainder_004
 * @tc.desc: Verify getting remainder for valid version.
 * @tc.type: FUNC
 * @tc.require: issueI000002
 */
HWTEST_F(QrcodeVersionTest, qrcode_version_get_remainder_004, TestSize.Level1)
{
    int32_t remainder = QrcodeVersionGetRemainder(1);
    EXPECT_GE(remainder, 0);
}

/**
 * @tc.name: qrcode_version_mode_length_005
 * @tc.desc: Verify getting mode length for numeric mode.
 * @tc.type: FUNC
 * @tc.require: issueI000002
 */
HWTEST_F(QrcodeVersionTest, qrcode_version_mode_length_005, TestSize.Level1)
{
    int32_t length = QrcodeVersionModeLength(QRCODE_MODE_NUM, 1);
    EXPECT_GT(length, 0);
}

/**
 * @tc.name: qrcode_version_mode_length_an_006
 * @tc.desc: Verify getting mode length for alphanumeric mode.
 * @tc.type: FUNC
 * @tc.require: issueI000002
 */
HWTEST_F(QrcodeVersionTest, qrcode_version_mode_length_an_006, TestSize.Level1)
{
    int32_t length = QrcodeVersionModeLength(QRCODE_MODE_AN, 1);
    EXPECT_GT(length, 0);
}

/**
 * @tc.name: qrcode_version_mode_length_8_007
 * @tc.desc: Verify getting mode length for byte mode.
 * @tc.type: FUNC
 * @tc.require: issueI000002
 */
HWTEST_F(QrcodeVersionTest, qrcode_version_mode_length_8_007, TestSize.Level1)
{
    int32_t length = QrcodeVersionModeLength(QRCODE_MODE_8, 1);
    EXPECT_GT(length, 0);
}

/**
 * @tc.name: qrcode_version_max_words_008
 * @tc.desc: Verify getting max words in numeric mode.
 * @tc.type: FUNC
 * @tc.require: issueI000002
 */
HWTEST_F(QrcodeVersionTest, qrcode_version_max_words_008, TestSize.Level1)
{
    int32_t maxWords = QrcodeVersionMaxWordsInMode(1, QRCODE_MODE_NUM);
    EXPECT_GT(maxWords, 0);
}

/**
 * @tc.name: qrcode_version_set_ecc_009
 * @tc.desc: Verify setting ECC level.
 * @tc.type: FUNC
 * @tc.require: issueI000002
 */
HWTEST_F(QrcodeVersionTest, qrcode_version_set_ecc_009, TestSize.Level1)
{
    QrcodeVersionSetEcc(QRCODE_ECC_MEDIUM);
}

/**
 * @tc.name: qrcode_version_get_ecc_info_010
 * @tc.desc: Verify getting ECC info for valid version.
 * @tc.type: FUNC
 * @tc.require: issueI000002
 */
HWTEST_F(QrcodeVersionTest, qrcode_version_get_ecc_info_010, TestSize.Level1)
{
    int32_t spec[5];
    QrcodeVersionGetEccInfo(1, spec, 5);
    EXPECT_GT(spec[0], 0);
}

/**
 * @tc.name: qrcode_version_get_pattern_011
 * @tc.desc: Verify getting pattern for valid version.
 * @tc.type: FUNC
 * @tc.require: issueI000002
 */
HWTEST_F(QrcodeVersionTest, qrcode_version_get_pattern_011, TestSize.Level1)
{
    uint32_t pattern = QrcodeVersionGetPattern(7);
    EXPECT_NE(pattern, 0);
}

/**
 * @tc.name: qrcode_version_get_format_info_012
 * @tc.desc: Verify getting format info.
 * @tc.type: FUNC
 * @tc.require: issueI000002
 */
HWTEST_F(QrcodeVersionTest, qrcode_version_get_format_info_012, TestSize.Level1)
{
    int32_t formatInfo = QrcodeVersionGetFormatInfo(0);
    EXPECT_NE(formatInfo, 0);
}

/**
 * @tc.name: qrcode_version_new_data_013
 * @tc.desc: Verify creating new data buffer.
 * @tc.type: FUNC
 * @tc.require: issueI000002
 */
HWTEST_F(QrcodeVersionTest, qrcode_version_new_data_013, TestSize.Level1)
{
    uint8_t *data = QrcodeVersionNewData(1);
    EXPECT_NE(data, nullptr);
    if (data != nullptr) {
        QrcodeFree(data);
    }
}

/**
 * @tc.name: qrcode_version_clear_cache_014
 * @tc.desc: Verify clearing cache.
 * @tc.type: FUNC
 * @tc.require: issueI000002
 */
HWTEST_F(QrcodeVersionTest, qrcode_version_clear_cache_014, TestSize.Level1)
{
    QrcodeVersionClearCache(1);
}

/**
 * @tc.name: qrcode_version_get_min_version_015
 * @tc.desc: Verify getting minimum version for size.
 * @tc.type: FUNC
 * @tc.require: issueI000002
 */
HWTEST_F(QrcodeVersionTest, qrcode_version_get_min_version_015, TestSize.Level1)
{
    int32_t minVersion = QrcodeVersionGetMinVersion(10);
    EXPECT_GE(minVersion, 1);
}

/**
 * @tc.name: qrcode_version_max_version_016
 * @tc.desc: Verify functions work with max version.
 * @tc.type: FUNC
 * @tc.require: issueI000002
 */
HWTEST_F(QrcodeVersionTest, qrcode_version_max_version_016, TestSize.Level1)
{
    int32_t dataLen = QrcodeVersionGetDataLen(QRCODE_VERSION_MAX);
    EXPECT_GT(dataLen, 0);

    int32_t width = QrcodeVersionGetWidth(QRCODE_VERSION_MAX);
    EXPECT_GT(width, 0);
}

/**
 * @tc.name: qrcode_version_invalid_mode_017
 * @tc.desc: Verify handling invalid mode.
 * @tc.type: FUNC
 * @tc.require: issueI000002
 */
HWTEST_F(QrcodeVersionTest, qrcode_version_invalid_mode_017, TestSize.Level1)
{
    int32_t length = QrcodeVersionModeLength(QRCODE_MODE_NUL, 1);
    EXPECT_EQ(length, 0);
}

/**
 * @tc.name: qrcode_version_zero_version_018
 * @tc.desc: Verify handling zero version.
 * @tc.type: FUNC
 * @tc.require: issueI000002
 */
HWTEST_F(QrcodeVersionTest, qrcode_version_zero_version_018, TestSize.Level1)
{
    int32_t dataLen = QrcodeVersionGetDataLen(0);
    EXPECT_EQ(dataLen, 0);
}