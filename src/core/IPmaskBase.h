#pragma once
#ifndef IPMASK_H
#define IPMASK_H

#include "IPaddressBase.h"
#include "IIPmask.h"

namespace core {
    class IPmaskBase : public virtual IPaddressBase, public IIPmask
    {
    public:
        IPmaskBase(const boost::dynamic_bitset<>& maskAddress);

        short getPrefix() const final;

        friend std::istream& operator>>(std::istream&, std::shared_ptr<IPmaskBase>&);

        virtual ~IPmaskBase() = default;
    };
};

#endif // IPMASK_H
