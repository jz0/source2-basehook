#pragma once

struct Netvar 
{
    const char* NetvarName; 
    void* _pad[2]; 
    uint32_t Offset; 
    uint32_t something; 
    void* _pad2[10];
    const char* TypeName; 
    void* _pad3[5];
};

struct NetvarWrapper
{
    Netvar* Netvar;
    char pad[7];
}Packed;

struct SchemaRecvTable 
{
    const char* varName;
    void* _pad;
    int32_t NumOfNetvars;
    int32_t unknown;
    NetvarWrapper* NetvarsArray;
};