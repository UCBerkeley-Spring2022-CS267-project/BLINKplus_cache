#include <cstdio>

#include <cuda_runtime.h>
#include <nccl.h>


#include "extern_lib.h"

ncclResult_t  ncclAllReduce(const void* sendbuff, void* recvbuff, size_t count,
    ncclDataType_t datatype, ncclRedOp_t op, ncclComm_t comm, cudaStream_t stream) {
    // TODO: why it is printed twice?
    printf("My Implementation\n");
    return EXTERN_LIB(ncclAllReduce, sendbuff, recvbuff, count, datatype, op, comm, stream);
}    
