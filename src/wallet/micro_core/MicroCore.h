#ifndef ETN01_MICROCORE_H
#define ETN01_MICROCORE_H

#include <iostream>

#include "electroneum_headers.h"
#include "tools.h"

namespace etneg
{
  using namespace cryptonote;
  using namespace crypto;
  using namespace std;

  /**
       * Micro version of cryptonode::core class
       * Micro version of constructor,
       * init and destructor are implemted.
       *
       * Just enough to read the blockchain
       * database for use in the example.
       */
  class MicroCore
  {
      string blockchain_path;

      tx_memory_pool m_mempool;
      Blockchain m_blockchain_storage;

    public:
      MicroCore();

      bool init(const string &_blockchain_path, bool testnet = false);

      Blockchain& get_core();

      bool get_block_by_height(const uint64_t &height, block &blk);

      bool get_tx(const crypto::hash &tx_hash, transaction &tx);

      bool get_tx(const string &tx_hash, transaction &tx);

      bool find_output_in_tx(const transaction &tx, const public_key &output_pubkey, tx_out &out, size_t &output_index);

      bool get_tx_hash_from_output_pubkey(const public_key &output_pubkey, const uint64_t &block_height, crypto::hash &tx_hash, transaction &tx_found);

      uint64_t get_blk_timestamp(uint64_t blk_height);

      string get_blkchain_path();

      virtual ~MicroCore();
  };

  bool init_blockchain(const string &path, MicroCore *&mcore, Blockchain *&core_storage, bool testnet = false);

}

#endif