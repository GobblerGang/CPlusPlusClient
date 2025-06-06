#pragma once

#include <string>
#include <vector>
#include <optional>
#include <nlohmann/json.hpp>

class PAC {
public:
    std::string recipient_id;
    std::string file_uuid;
    std::string valid_until;  // ISO 8601 string format
    std::string encrypted_file_key;
    std::string signature;
    std::string issuer_id;
    std::string sender_ephemeral_public;
    std::string k_file_nonce;
    std::string filename;
    std::string mime_type;
    std::string issuer_username;
    std::string recipient_username;

    PAC() = default;

    PAC(const std::string& recipient_id,
        const std::string& file_uuid,
        const std::string& valid_until,
        const std::string& encrypted_file_key,
        const std::string& signature,
        const std::string& issuer_id,
        const std::string& sender_ephemeral_public,
        const std::string& k_file_nonce,
        const std::string& filename,
        const std::string& mime_type,
        const std::string& issuer_username,
        const std::string& recipient_username);

    static PAC from_json(const nlohmann::json& data);
    nlohmann::json to_json() const;
};

