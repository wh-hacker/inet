//
// Copyright (C) 2013 OpenSim Ltd.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

#ifndef __INET_ERRORMODELBASE_H
#define __INET_ERRORMODELBASE_H

#include "inet/physicallayer/contract/packetlevel/IErrorModel.h"

namespace inet {

namespace physicallayer {

class INET_API ErrorModelBase : public cModule, public IErrorModel
{
  public:
    enum class CorruptionMode {
        CM_UNDEFINED = -1,
        CM_PACKET,
        CM_CHUNK,
        CM_BYTE,
        CM_BIT
    };

  protected:
    CorruptionMode corruptionMode = CorruptionMode::CM_UNDEFINED;

  protected:
    virtual void initialize(int stage) override;

    virtual bool hasProbabilisticError(b length, double ber) const;

    virtual Packet *corruptBits(const Packet *packet, double ber, bool& isCorrupted) const;
    virtual Packet *corruptBytes(const Packet *packet, double ber, bool& isCorrupted) const;
    virtual Packet *corruptChunks(const Packet *packet, double ber, bool& isCorrupted) const;
    virtual Packet *corruptPacket(const Packet *packet, bool& isCorrupted) const;

    virtual Packet *computeCorruptedPacket(const Packet *packet, double ber) const;
    virtual Packet *computeCorruptedPacket(const ISnir *snir) const override;
};

} // namespace physicallayer

} // namespace inet

#endif // ifndef __INET_ERRORMODELBASE_H

