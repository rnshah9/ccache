#include <stdint.h>
#include <stdio.h>
#include <climits>
#include "Util.hpp"

#include <fuzzer/FuzzedDataProvider.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    uint64_t x = provider.ConsumeIntegral<uint64_t>();

    Util::format_human_readable_size(x);

    return 0;
}