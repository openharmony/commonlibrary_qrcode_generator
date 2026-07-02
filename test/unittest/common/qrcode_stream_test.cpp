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

#include "interfaces/innerkits/qrcode_stream.h"
#include "interfaces/innerkits/qrcode_inner.h"
#include <gtest/gtest.h>
#include <cstring>

using namespace testing::ext;

class QrcodeStreamTest : public testing::Test {
public:
    static void SetUpTestCase(void);
    static void TearDownTestCase(void);
    void SetUp();
    void TearDown();
};

void QrcodeStreamTest::SetUpTestCase(void) {}

void QrcodeStreamTest::TearDownTestCase(void) {}

void QrcodeStreamTest::SetUp(void) {}

void QrcodeStreamTest::TearDown(void) {}

/**
 * @tc.name: qrcode_stream_new_001
 * @tc.desc: Verify creating new stream.
 * @tc.type: FUNC
 * @tc.require: issueI000004
 */
HWTEST_F(QrcodeStreamTest, qrcode_stream_new_001, TestSize.Level1)
{
    QrcodeStream *stream = QrcodeStreamNew();
    EXPECT_NE(stream, nullptr);
    if (stream != nullptr) {
        QrcodeStreamFree(stream);
    }
}

/**
 * @tc.name: qrcode_stream_add_num_002
 * @tc.desc: Verify adding number to stream.
 * @tc.type: FUNC
 * @tc.require: issueI000004
 */
HWTEST_F(QrcodeStreamTest, qrcode_stream_add_num_002, TestSize.Level1)
{
    QrcodeStream *stream = QrcodeStreamNew();
    EXPECT_NE(stream, nullptr);
    if (stream != nullptr) {
        int32_t ret = QrcodeStreamAddNum(stream, 4, 0b1010);
        EXPECT_EQ(ret, 0);
        QrcodeStreamFree(stream);
    }
}

/**
 * @tc.name: qrcode_stream_add_bytes_003
 * @tc.desc: Verify adding bytes to stream.
 * @tc.type: FUNC
 * @tc.require: issueI000004
 */
HWTEST_F(QrcodeStreamTest, qrcode_stream_add_bytes_003, TestSize.Level1)
{
    QrcodeStream *stream = QrcodeStreamNew();
    EXPECT_NE(stream, nullptr);
    if (stream != nullptr) {
        const uint8_t data[] = {0x12, 0x34, 0x56};
        int32_t ret = QrcodeStreamAddBytes(stream, 3, (uint8_t *)data);
        EXPECT_EQ(ret, 0);
        QrcodeStreamFree(stream);
    }
}

/**
 * @tc.name: qrcode_stream_dup_data_004
 * @tc.desc: Verify duplicating stream data.
 * @tc.type: FUNC
 * @tc.require: issueI000004
 */
HWTEST_F(QrcodeStreamTest, qrcode_stream_dup_data_004, TestSize.Level1)
{
    QrcodeStream *stream = QrcodeStreamNew();
    EXPECT_NE(stream, nullptr);
    if (stream != nullptr) {
        const uint8_t data[] = {0x12, 0x34, 0x56};
        QrcodeStreamAddBytes(stream, 3, (uint8_t *)data);
        uint8_t *dupData = QrcodeStreamDupData(stream);
        EXPECT_NE(dupData, nullptr);
        if (dupData != nullptr) {
            QrcodeFree(dupData);
        }
        QrcodeStreamFree(stream);
    }
}

/**
 * @tc.name: qrcode_stream_free_null_005
 * @tc.desc: Verify freeing null stream.
 * @tc.type: FUNC
 * @tc.require: issueI000004
 */
HWTEST_F(QrcodeStreamTest, qrcode_stream_free_null_005, TestSize.Level1)
{
    QrcodeStreamFree(nullptr);
}

/**
 * @tc.name: qrcode_stream_clean_006
 * @tc.desc: Verify cleaning stream.
 * @tc.type: FUNC
 * @tc.require: issueI000004
 */
HWTEST_F(QrcodeStreamTest, qrcode_stream_clean_006, TestSize.Level1)
{
    QrcodeStream *stream = QrcodeStreamNew();
    EXPECT_NE(stream, nullptr);
    if (stream != nullptr) {
        const uint8_t data[] = {0x12, 0x34, 0x56};
        QrcodeStreamAddBytes(stream, 3, (uint8_t *)data);
        QrcodeStreamClean(stream);
        QrcodeStreamFree(stream);
    }
}

/**
 * @tc.name: qrcode_stream_add_007
 * @tc.desc: Verify adding stream to stream.
 * @tc.type: FUNC
 * @tc.require: issueI000004
 */
HWTEST_F(QrcodeStreamTest, qrcode_stream_add_007, TestSize.Level1)
{
    QrcodeStream *stream1 = QrcodeStreamNew();
    QrcodeStream *stream2 = QrcodeStreamNew();
    EXPECT_NE(stream1, nullptr);
    EXPECT_NE(stream2, nullptr);
    if (stream1 != nullptr && stream2 != nullptr) {
        const uint8_t data[] = {0x12, 0x34};
        QrcodeStreamAddBytes(stream2, 2, (uint8_t *)data);
        int32_t ret = QrcodeStreamAdd(stream1, stream2);
        EXPECT_EQ(ret, 0);
        QrcodeStreamFree(stream1);
        QrcodeStreamFree(stream2);
    }
}

/**
 * @tc.name: qrcode_stream_add_multiple_008
 * @tc.desc: Verify adding multiple numbers to stream.
 * @tc.type: FUNC
 * @tc.require: issueI000004
 */
HWTEST_F(QrcodeStreamTest, qrcode_stream_add_multiple_008, TestSize.Level1)
{
    QrcodeStream *stream = QrcodeStreamNew();
    EXPECT_NE(stream, nullptr);
    if (stream != nullptr) {
        QrcodeStreamAddNum(stream, 4, 0b1010);
        QrcodeStreamAddNum(stream, 4, 0b0101);
        QrcodeStreamAddNum(stream, 8, 0xFF);
        uint8_t *dupData = QrcodeStreamDupData(stream);
        EXPECT_NE(dupData, nullptr);
        if (dupData != nullptr) {
            QrcodeFree(dupData);
        }
        QrcodeStreamFree(stream);
    }
}

/**
 * @tc.name: qrcode_stream_bit_count_009
 * @tc.desc: Verify stream bit count is updated.
 * @tc.type: FUNC
 * @tc.require: issueI000004
 */
HWTEST_F(QrcodeStreamTest, qrcode_stream_bit_count_009, TestSize.Level1)
{
    QrcodeStream *stream = QrcodeStreamNew();
    EXPECT_NE(stream, nullptr);
    if (stream != nullptr) {
        QrcodeStreamAddNum(stream, 4, 0b1010);
        EXPECT_EQ(stream->bitCount, 4);
        QrcodeStreamAddNum(stream, 8, 0xFF);
        EXPECT_EQ(stream->bitCount, 12);
        QrcodeStreamFree(stream);
    }
}

/**
 * @tc.name: qrcode_stream_empty_dup_010
 * @tc.desc: Verify duplicating empty stream data.
 * @tc.type: FUNC
 * @tc.require: issueI000004
 */
HWTEST_F(QrcodeStreamTest, qrcode_stream_empty_dup_010, TestSize.Level1)
{
    QrcodeStream *stream = QrcodeStreamNew();
    EXPECT_NE(stream, nullptr);
    if (stream != nullptr) {
        uint8_t *dupData = QrcodeStreamDupData(stream);
        EXPECT_NE(dupData, nullptr);
        if (dupData != nullptr) {
            QrcodeFree(dupData);
        }
        QrcodeStreamFree(stream);
    }
}