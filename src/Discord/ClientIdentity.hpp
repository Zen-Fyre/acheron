#pragma once

#include <QString>
#include <QMutex>

#include <optional>

#include "Objects.hpp"

namespace Acheron {
namespace Discord {

struct ClientPropertiesBuildParams
{
    bool includeClientHeartbeatSessionId;
    std::optional<bool> isFastConnect;
    std::optional<QString> gatewayConnectReasons;
};

class ClientIdentity
{
public:
    ClientIdentity();

    // QString getLaunchId() const;
    // QString getLaunchSignature() const;

    void regenerateClientHeartbeatSessionId();

    void setDiscordLocale(const QString &locale);
    QString discordLocale() const;

    void setAppFocused(bool focused);

    ClientProperties buildClientProperties(const ClientPropertiesBuildParams &params) const;

private:
    static QString generateLaunchSignature();

    mutable QMutex mutex;
    QString launchId;
    QString launchSignature;
    QString clientHeartbeatSessionId;
    QString locale = "en-US";
    bool appFocused = true;
};

} // namespace Discord
} // namespace Acheron
