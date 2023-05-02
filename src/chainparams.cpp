// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}


class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xe4;
        pchMessageStart[1] = 0xe7;
        pchMessageStart[2] = 0xe9;
        pchMessageStart[3] = 0xe4;
        vAlertPubKey = ParseHex("04cc548f0e1feed92db95c1b52ae89742bf55a6d7649b82a2c9e95502287627a48806be6fa4181ad6e23d8497c3a07dfcc12badec484b9a85b4f67aec0c4ccdab5");
        nDefaultPort = 4555;
        nRPCPort = 4444;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 24);

        //   vMerkleTree:  60aeca51b138f65fcfdd0e188859ad6ae06ea37a85471e865110c6828520d6c0

        // MAINNET
        // CBlock(hash=000000bc0ddf15573115c44b81d8b10e9ebd868b5c967f408bda273656f30e28, ver=1, hashPrevBlock=0000000000000000000000000000000000000000000000000000000000000000, hashMerkleRoot=60aeca51b138f65fcfdd0e188859ad6ae06ea37a85471e865110c6828520d6c0, nTime=1678306980, nBits=1e00ffff, nNonce=6401794, vtx=1, vchBlockSig=)
        //   Coinbase(hash=60aeca51b138f65fcfdd0e188859ad6ae06ea37a85471e865110c6828520d6c0, nTime=1678306980, ver=1, vin.size=1, vout.size=1, nLockTime=0, strTxComment=dem v2 genesis block)
        //     CTxIn(COutPoint(0000000000, 4294967295), coinbase 04ffff001d020f2742446f6e277420747275737420796f75722062616e6b202d20547275737420446575747363686520654d61726b21203732646533623132313820313136303635353031)
        //     CTxOut(empty)
        //

        const char* pszTimestamp = "Don't trust your bank - Trust Deutsche eMark! 72de3b1218 116065501";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 486604799 << CBigNum(9999) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();

        // TX Comment
        std::string strTxComment = "dem v2 genesis block";

        CTransaction txNew(1, 1678306980, vin, vout, 0, strTxComment); //TX Comment

        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1678306980;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 6401794;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x000000bc0ddf15573115c44b81d8b10e9ebd868b5c967f408bda273656f30e28"));
        assert(genesis.hashMerkleRoot == uint256("0x60aeca51b138f65fcfdd0e188859ad6ae06ea37a85471e865110c6828520d6c0"));

        // SIPA DNS Seeders
	//
	//     test with 'dig' command
	//
	//     	    examples:  dig dnsseed.emarks.cc A		     //     A for IPv4
        //                     dig dnsseed.deutsche-emark.cc AAAA    //  AAAA for IPv6
	//		       dig dem-seed1.communitycoins.org A
	//                     dig dem-seed2.communitycoins.ort AAAA
	//
        //     chainetics.com (dbkeys)
        //                              Domain                          Sub-Domain
        vSeeds.push_back(CDNSSeedData("emarks.cc",          "dnsseed.emarks.cc" ));
        vSeeds.push_back(CDNSSeedData("deutsche-emark.cc",  "dnsseed.deutsche-emark.cc" ));
	//
        //     communitycoins.org
        //                              Domain                          Sub-Domain
        vSeeds.push_back(CDNSSeedData("communitycoins.org", "dem-seed1.communitycoins.org" ));
        vSeeds.push_back(CDNSSeedData("communitycoins.org", "dem-seed2.communitycoins.org" ));
        vSeeds.push_back(CDNSSeedData("communitycoins.org", "dem-seed3.communitycoins.org" ));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 53);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 30);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1, 181);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xfe;
        pchMessageStart[1] = 0xc3;
        pchMessageStart[2] = 0xbe;
        pchMessageStart[3] = 0xd9;

        // TESTNET
        // CBlock(hash=0000752b9e9142c3ec3d9e84f86feb59ce9e7e44d64996b5a021dbf55e3b4355, ver=1, hashPrevBlock=0000000000000000000000000000000000000000000000000000000000000000, hashMerkleRoot=60aeca51b138f65fcfdd0e188859ad6ae06ea37a85471e865110c6828520d6c0, nTime=1678306980, nBits=1f00ffff, nNonce=39551, vtx=1, vchBlockSig=)
        //   Coinbase(hash=60aeca51b138f65fcfdd0e188859ad6ae06ea37a85471e865110c6828520d6c0, nTime=1678306980, ver=1, vin.size=1, vout.size=1, nLockTime=0, strTxComment=dem v2 genesis block)
        //     CTxIn(COutPoint(0000000000, 4294967295), coinbase 04ffff001d020f2742446f6e277420747275737420796f75722062616e6b202d20547275737420446575747363686520654d61726b21203732646533623132313820313136303635353031)
        //     CTxOut(empty)
        //

        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        vAlertPubKey = ParseHex("04b8c8527578d8d6023f0b8736eb9b929f045441b5dd0ac3339b5a821dc462eba60029e94bfb55766445951d5da3913333d91539f205573d436375cdf0d4859a62");
        nDefaultPort = 14555;
        nRPCPort = 14444;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 39551;
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x0000752b9e9142c3ec3d9e84f86feb59ce9e7e44d64996b5a021dbf55e3b4355"));
        assert(genesis.hashMerkleRoot == uint256("0x60aeca51b138f65fcfdd0e188859ad6ae06ea37a85471e865110c6828520d6c0"));

        vFixedSeeds.clear();
        vSeeds.clear();

        // SIPA DNS Seeders for Testnet
        //
        //     test with 'dig' command
        //
        //          examples:  dig testnet.emarks.cc A               //     A for IPv4
        //            	       dig testnet.emarks.cc AAAA            //     A for IPv6
        //
        //                              Domain                    Sub-Domain
        vSeeds.push_back(CDNSSeedData("emarks.cc",          "testnet.emarks.cc" ));


        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 196);
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1, 239);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xba;
        pchMessageStart[3] = 0xd5;

        // REGTEST
        // CBlock(hash=00139c39e6641a864a384ba4f6b351e98498e7e3ee7463433e8440ad307450f2, ver=1, hashPrevBlock=0000000000000000000000000000000000000000000000000000000000000000, hashMerkleRoot=60aeca51b138f65fcfdd0e188859ad6ae06ea37a85471e865110c6828520d6c0, nTime=1678306980, nBits=2000ffff, nNonce=51, vtx=1, vchBlockSig=)
        //   Coinbase(hash=60aeca51b138f65fcfdd0e188859ad6ae06ea37a85471e865110c6828520d6c0, nTime=1678306980, ver=1, vin.size=1, vout.size=1, nLockTime=0, strTxComment=dem v2 genesis block)
        //     CTxIn(COutPoint(0000000000, 4294967295), coinbase 04ffff001d020f2742446f6e277420747275737420796f75722062616e6b202d20547275737420446575747363686520654d61726b21203732646533623132313820313136303635353031)
        //     CTxOut(empty)
        //

        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 8);
        genesis.nTime = 1678306980;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 51;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 24555;
        strDataDir = "regtest";
        assert(hashGenesisBlock == uint256("0x00139c39e6641a864a384ba4f6b351e98498e7e3ee7463433e8440ad307450f2"));
        assert(genesis.hashMerkleRoot == uint256("0x60aeca51b138f65fcfdd0e188859ad6ae06ea37a85471e865110c6828520d6c0"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
