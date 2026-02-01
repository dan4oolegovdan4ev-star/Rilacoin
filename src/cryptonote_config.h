// Copyright (c) 2014-2024, The Monero Project
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

#pragma once

#include <cstdint>
#include <stdexcept>
#include <string>
#include <boost/uuid/uuid.hpp>

#define CRYPTONOTE_DNS_TIMEOUT_MS                       20000

#define CRYPTONOTE_MAX_BLOCK_NUMBER                     500000000
#define CRYPTONOTE_MAX_TX_SIZE                          1000000
#define CRYPTONOTE_MAX_TX_PER_BLOCK                     0x10000000
#define CRYPTONOTE_PUBLIC_ADDRESS_TEXTBLOB_VER          0
#define CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW            60
#define CURRENT_TRANSACTION_VERSION                     2
#define CURRENT_BLOCK_MAJOR_VERSION                     1
#define CURRENT_BLOCK_MINOR_VERSION                     0
#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT              60*60*2
#define CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE             10

#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW               60

// MONEY_SUPPLY - total number coins to be generated
#define MONEY_SUPPLY                                    ((uint64_t)2100000000000000) // 2.1 quadrillion atomic units
#define EMISSION_SPEED_FACTOR_PER_MINUTE                (20)
#define FINAL_SUBSIDY_PER_MINUTE                        ((uint64_t)300000000000) // 3 * pow(10, 11)

#define CRYPTONOTE_REWARD_BLOCKS_WINDOW                 100
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2    60000
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1    20000
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V5    300000
#define CRYPTONOTE_LONG_TERM_BLOCK_WEIGHT_WINDOW_SIZE   100000
#define CRYPTONOTE_SHORT_TERM_BLOCK_WEIGHT_SURGE_FACTOR 50
#define CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE          600
#define CRYPTONOTE_DISPLAY_DECIMAL_POINT                12
#define COIN                                            ((uint64_t)1000000000) // 1 coin = 10^9 atomic units

#define FEE_PER_KB_OLD                                  ((uint64_t)10000000000)
#define FEE_PER_KB                                      ((uint64_t)2000000000)
#define FEE_PER_BYTE                                    ((uint64_t)300000)
#define DYNAMIC_FEE_PER_KB_BASE_FEE                     ((uint64_t)2000000000)
#define DYNAMIC_FEE_PER_KB_BASE_BLOCK_REWARD            ((uint64_t)10000000000000)
#define DYNAMIC_FEE_PER_KB_BASE_FEE_V5                  ((uint64_t)2000000000 * (uint64_t)CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2 / CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V5)
#define DYNAMIC_FEE_REFERENCE_TRANSACTION_WEIGHT        ((uint64_t)3000)

#define ORPHANED_BLOCKS_MAX_COUNT                       100

#define DIFFICULTY_TARGET_V2                            120
#define DIFFICULTY_TARGET_V1                            60
#define DIFFICULTY_WINDOW                               720
#define DIFFICULTY_LAG                                  15
#define DIFFICULTY_CUT                                  60
#define DIFFICULTY_BLOCKS_COUNT                         DIFFICULTY_WINDOW + DIFFICULTY_LAG

#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS_V1   DIFFICULTY_TARGET_V1 * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS_V2   DIFFICULTY_TARGET_V2 * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS       1

#define DIFFICULTY_BLOCKS_ESTIMATE_TIMESPAN             DIFFICULTY_TARGET_V1

#define BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT          10000
#define BLOCKS_IDS_SYNCHRONIZING_MAX_COUNT              25000
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT_PRE_V4       100
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT              20
#define BLOCKS_SYNCHRONIZING_MAX_COUNT                  2048

#define CRYPTONOTE_MEMPOOL_TX_LIVETIME                    (86400*3)
#define CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME     604800

#define CRYPTONOTE_DANDELIONPP_STEMS              2
#define CRYPTONOTE_DANDELIONPP_FLUFF_PROBABILITY 20
#define CRYPTONOTE_DANDELIONPP_MIN_EPOCH         10
#define CRYPTONOTE_DANDELIONPP_EPOCH_RANGE       30
#define CRYPTONOTE_DANDELIONPP_FLUSH_AVERAGE      5
#define CRYPTONOTE_DANDELIONPP_EMBARGO_AVERAGE   39

#define CRYPTONOTE_NOISE_MIN_EPOCH                      5
#define CRYPTONOTE_NOISE_EPOCH_RANGE                    30
#define CRYPTONOTE_NOISE_MIN_DELAY                      10
#define CRYPTONOTE_NOISE_DELAY_RANGE                    5
#define CRYPTONOTE_NOISE_BYTES                          3*1024
#define CRYPTONOTE_NOISE_CHANNELS                       2

#define CRYPTONOTE_FORWARD_DELAY_BASE (CRYPTONOTE_NOISE_MIN_DELAY + CRYPTONOTE_NOISE_DELAY_RANGE)
#define CRYPTONOTE_FORWARD_DELAY_AVERAGE (CRYPTONOTE_FORWARD_DELAY_BASE + (CRYPTONOTE_FORWARD_DELAY_BASE / 2))

#define CRYPTONOTE_MAX_FRAGMENTS                        20

#define COMMAND_RPC_GET_BLOCKS_FAST_MAX_BLOCK_COUNT     1000
#define COMMAND_RPC_GET_BLOCKS_FAST_MAX_TX_COUNT        20000
#define DEFAULT_RPC_MAX_CONNECTIONS_PER_PUBLIC_IP       3
#define DEFAULT_RPC_MAX_CONNECTIONS_PER_PRIVATE_IP      25
#define DEFAULT_RPC_MAX_CONNECTIONS                     100
#define DEFAULT_RPC_SOFT_LIMIT_SIZE                     25 * 1024 * 1024
#define MAX_RPC_CONTENT_LENGTH                          1048576

#define P2P_LOCAL_WHITE_PEERLIST_LIMIT                  1000
#define P2P_LOCAL_GRAY_PEERLIST_LIMIT                   5000

#define P2P_DEFAULT_CONNECTIONS_COUNT                   12
#define P2P_DEFAULT_HANDSHAKE_INTERVAL                  60
#define P2P_DEFAULT_PACKET_MAX_SIZE                     50000000
#define P2P_DEFAULT_PEERS_IN_HANDSHAKE                  250
#define P2P_MAX_PEERS_IN_HANDSHAKE                      250
#define P2P_DEFAULT_CONNECTION_TIMEOUT                  5000
#define P2P_DEFAULT_SOCKS_CONNECT_TIMEOUT               45
#define P2P_DEFAULT_PING_CONNECTION_TIMEOUT             2000
#define P2P_DEFAULT_INVOKE_TIMEOUT                      60*2*1000
#define P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT            5000
#define P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT       70
#define P2P_DEFAULT_ANCHOR_CONNECTIONS_COUNT            2
#define P2P_DEFAULT_SYNC_SEARCH_CONNECTIONS_COUNT       2
#define P2P_DEFAULT_LIMIT_RATE_UP                       8192
#define P2P_DEFAULT_LIMIT_RATE_DOWN                     32768

#define P2P_FAILED_ADDR_FORGET_SECONDS                  (60*60)
#define P2P_IP_BLOCKTIME                                (60*60*24)
#define P2P_IP_FAILS_BEFORE_BLOCK                       10
#define P2P_IDLE_CONNECTION_KILL_INTERVAL               (5*60)

#define P2P_SUPPORT_FLAG_FLUFFY_BLOCKS                  0x01
#define P2P_SUPPORT_FLAGS                               P2P_SUPPORT_FLAG_FLUFFY_BLOCKS

#define RPC_IP_FAILS_BEFORE_BLOCK                       3

#define CRYPTONOTE_NAME                         "Rilacoin"
#define CRYPTONOTE_BLOCKCHAINDATA_FILENAME      "rilacoin_data.mdb"
#define CRYPTONOTE_BLOCKCHAINDATA_LOCK_FILENAME "rilacoin_lock.mdb"
#define P2P_NET_DATA_FILENAME                   "rilacoin_p2pstate.bin"
#define RPC_PAYMENTS_DATA_FILENAME              "rilacoin_rpcpayments.bin"
#define MINER_CONFIG_FILE_NAME                  "rilacoin_miner_conf.json"

#define THREAD_STACK_SIZE                       5 * 1024 * 1024

#define HF_VERSION_DYNAMIC_FEE                  4
#define HF_VERSION_MIN_MIXIN_4                  6
#define HF_VERSION_MIN_MIXIN_6                  7
#define HF_VERSION_MIN_MIXIN_10                 8
#define HF_VERSION_MIN_MIXIN_15                 15
#define HF_VERSION_ENFORCE_RCT                  6
#define HF_VERSION_PER_BYTE_FEE                 8
#define HF_VERSION_SMALLER_BP                   10
#define HF_VERSION_LONG_TERM_BLOCK_WEIGHT       10
#define HF_VERSION_MIN_2_OUTPUTS                12
#define HF_VERSION_MIN_V2_COINBASE_TX           12
#define HF_VERSION_SAME_MIXIN                   12
#define HF_VERSION_REJECT_SIGS_IN_COINBASE      12
#define HF_VERSION_ENFORCE_MIN_AGE              12
#define HF_VERSION_EFFECTIVE_SHORT_TERM_MEDIAN_IN_PENALTY 12
#define HF_VERSION_EXACT_COINBASE               13
#define HF_VERSION_CLSAG                        13
#define HF_VERSION_DETERMINISTIC_UNLOCK_TIME    13
#define HF_VERSION_BULLETPROOF_PLUS             15
#define HF_VERSION_VIEW_TAGS                    15
#define HF_VERSION_2021_SCALING                 15

#define PER_KB_FEE_QUANTIZATION_DECIMALS        8
#define CRYPTONOTE_SCALING_2021_FEE_ROUNDING_PLACES 2

#define HASH_OF_HASHES_STEP                     512

#define DEFAULT_TXPOOL_MAX_WEIGHT               648000000ull

#define BULLETPROOF_MAX_OUTPUTS                 16
#define BULLETPROOF_PLUS_MAX_OUTPUTS            16

#define CRYPTONOTE_PRUNING_STRIPE_SIZE          4096
#define CRYPTONOTE_PRUNING_LOG_STRIPES          3
#define CRYPTONOTE_PRUNING_TIP_BLOCKS           5500

#define RPC_CREDITS_PER_HASH_SCALE ((float)(1<<24))

#define DNS_BLOCKLIST_LIFETIME (86400 * 8)

#define MAX_TX_EXTRA_SIZE                       1060

namespace config
{
  uint64_t const DEFAULT_FEE_ATOMIC_XMR_PER_KB = 500;
  uint8_t const FEE_CALCULATION_MAX_RETRIES = 10;
  uint64_t const DEFAULT_DUST_THRESHOLD = ((uint64_t)2000000000);
  uint64_t const BASE_REWARD_CLAMP_THRESHOLD = ((uint64_t)100000000);

  uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 19;
  uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 20;
  uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 42;
  uint16_t const P2P_DEFAULT_PORT = 22022;
  uint16_t const RPC_DEFAULT_PORT = 22023;
  uint16_t const ZMQ_RPC_DEFAULT_PORT = 22024;
  boost::uuids::uuid const NETWORK_ID = { {
      0xA1,0xB2,0xC3,0xD4,0xE5,0xF6,0x01,0x23,0x45,0x67,0x89,0xAB,0xCD,0xEF,0x11,0x22
  } };
  std::string const GENESIS_TX = "Rilacoin GENESIS TX PLACEHOLDER";
  uint32_t const GENESIS_NONCE = 10000;

  // ... testnet
  namespace testnet
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 53;
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 54;
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 63;
    uint16_t const P2P_DEFAULT_PORT = 22122;
    uint16_t const RPC_DEFAULT_PORT = 22123;
    uint16_t const ZMQ_RPC_DEFAULT_PORT = 22124;
    boost::uuids::uuid const NETWORK_ID = { {
        0xA2,0xB3,0xC4,0xD5,0xE6,0xF7,0x02,0x34,0x56,0x78,0x9A,0xBC,0xDE,0xF0,0x12,0x23
    } };
    std::string const GENESIS_TX = "Rilacoin TESTNET GENESIS TX PLACEHOLDER";
    uint32_t const GENESIS_NONCE = 10001;
  }

  // ... stagenet
  namespace stagenet
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 24;
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 25;
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 36;
    uint16_t const P2P_DEFAULT_PORT = 22222;
    uint16_t const RPC_DEFAULT_PORT = 22223;
    uint16_t const ZMQ_RPC_DEFAULT_PORT = 22224;
    boost::uuids::uuid const NETWORK_ID = { {
        0xA3,0xB4,0xC5,0xD6,0xE7,0xF8,0x03,0x45,0x67,0x89,0xAB,0xCD,0xEF,0x01,0x23,0x24
    } };
    std::string const GENESIS_TX = "Rilacoin STAGENET GENESIS TX PLACEHOLDER";
    uint32_t const GENESIS_NONCE = 10002;
  }
}

namespace cryptonote
{
  enum network_type : uint8_t
  {
    MAINNET = 0,
    TESTNET,
    STAGENET,
    FAKECHAIN,
    UNDEFINED = 255
  };
  struct config_t
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX;
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX;
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX;
    uint16_t const P2P_DEFAULT_PORT;
    uint16_t const RPC_DEFAULT_PORT;
    uint16_t const ZMQ_RPC_DEFAULT_PORT;
    boost::uuids::uuid const NETWORK_ID;
    std::string const GENESIS_TX;
    uint32_t const GENESIS_NONCE;
  };
  inline const config_t& get_config(network_type nettype)
  {
    static const config_t mainnet = {
      ::config::CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX,
      ::config::CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX,
      ::config::CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX,
      ::config::P2P_DEFAULT_PORT,
      ::config::RPC_DEFAULT_PORT,
      ::config::ZMQ_RPC_DEFAULT_PORT,
      ::config::NETWORK_ID,
      ::config::GENESIS_TX,
      ::config::GENESIS_NONCE
    };
    static const config_t testnet = {
      ::config::testnet::CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX,
      ::config::testnet::CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX,
      ::config::testnet::CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX,
      ::config::testnet::P2P_DEFAULT_PORT,
      ::config::testnet::RPC_DEFAULT_PORT,
      ::config::testnet::ZMQ_RPC_DEFAULT_PORT,
      ::config::testnet::NETWORK_ID,
      ::config::testnet::GENESIS_TX,
      ::config::testnet::GENESIS_NONCE
    };
    static const config_t stagenet = {
      ::config::stagenet::CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX,
      ::config::stagenet::CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX,
      ::config::stagenet::CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX,
      ::config::stagenet::P2P_DEFAULT_PORT,
      ::config::stagenet::RPC_DEFAULT_PORT,
      ::config::stagenet::ZMQ_RPC_DEFAULT_PORT,
      ::config::stagenet::NETWORK_ID,
      ::config::stagenet::GENESIS_TX,
      ::config::stagenet::GENESIS_NONCE
    };
    switch (nettype)
    {
      case MAINNET: return mainnet;
      case TESTNET: return testnet;
      case STAGENET: return stagenet;
      case FAKECHAIN: return mainnet;
      default: throw std::runtime_error("Invalid network type");
    }
  };
}
