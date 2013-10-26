#ifndef OPCODES_H_
#define OPCODES_H_

#include "common.h"

namespace Opcodes
{
    //�����˼�Ȩ
    const uint32 C2SLoginReq     = 10000;
    const uint32 S2CLoginRsp     = 10001;
    const uint32 C2SRegisterReq  = 10002;            //ע������
    const uint32 S2CRegisterRsp  = 10003;            //ע���Ӧ
    const uint32 C2SGetPlayerProfileReq = 15000;
    const uint32 S2CError        = 99990;            //ע���Ӧ
    const uint32 S2CErrorEx      = 99991;            //ע���Ӧ
}

#endif