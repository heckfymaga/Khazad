//
// Created by Руслан on 21.03.2018.
//
#pragma once
//#ifndef KHAZARD_H
//#define KHAZARD_H
typedef unsigned char byte;
class Khazard {
public:
    Khazard(byte *key);
    void Encrypt(uint64_t block);
    void Decrypt(uint64_t block);
    static uint64_t Substitution(uint64_t a);
    static void PrintChunk(byte *chunk);
    static uint64_t LinearMul(uint64_t a);
    static uint64_t ConvertTo64(byte *a);


    uint64_t RoundStep(uint64_t key, uint64_t block);

private:
    uint64_t *Keys;
    byte static gAdd(byte a, byte b);
    byte static gMul(byte a, byte b);
    void DefineKeySeq(byte *key);
    uint64_t DefineKey(uint64_t bp, uint64_t p, int r);
    uint64_t DefineConstSeq(int r);
    byte static GetSValue(byte a);
};


//#endif KHAZARD_H
