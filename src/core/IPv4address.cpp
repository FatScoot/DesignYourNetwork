#include "IPv4address.h"

#include <QString>
#include <boost/asio/ip/address.hpp>
#include <boost/dynamic_bitset.hpp>
#include <string>
#include <memory>

namespace core {
    QString IPv4address::asStringDec() const
    {
        return boost::asio::ip::make_address_v4(_IpAddress.to_ulong()).to_string().c_str();
    };

    QString IPv4address::asStringBin() const
    {
        std::string stringBinary;
        boost::to_string(_IpAddress, stringBinary);

        for(short i = 8; i <= 26; i += 9)
            stringBinary.insert(stringBinary.begin()+ i, '.');

        return stringBinary.c_str();
    };

    IPv4address IPv4address::operator|(const IPv4address &var) const
    {
        return (this->_IpAddress | var._IpAddress);
    }

    std::shared_ptr<IPaddressBase> IPv4address::_applyMask(const boost::dynamic_bitset<>& maskBitset) const
    {
        return std::make_shared<IPv4address>(this->_IpAddress & maskBitset);
    };
};
