#pragma once
#include <array>

class MCP3208
{
private:
    // 入力チャンネル(CH0～7)の個数
    static constexpr int CH_COUNT = 8;

    // SPIのチャンネル番号(0または1)
    const int m_spiChannel;

    // CS(チップセレクト)のピン番号
    const int m_pinCs;

    // 基準電圧(V単位)
    const double m_vRef;

    // SPI通信が正常に初期化できたかどうか
    const bool m_spiInitialized;

    // 前回update時の値
    std::array<int, CH_COUNT> m_rawValues;

public:
    // コンストラクタ
    //  - spiChannel: SPIのチャンネル番号(0または1)
    //  - pinCs: CS(チップセレクト)のピン番号
    //  - vRef: 基準電圧(MCP3208のV_refピンに入力している電圧, V単位)
    MCP3208(int spiChannel, int pinCs, double vRef);
    ~MCP3208() = default;

    // 値を更新
    void update();

    // 指定された入力チャンネルの生の値を取得
    int rawValueAt(int ch) const;

    // 指定された入力チャンネルの電圧値(V単位)を取得
    double voltageAt(int ch) const;

    // SPIのチャンネル番号を取得
    int spiChannel() const;
};
