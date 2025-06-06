//
// Created by Ruairi on 04/06/2025.
//
#pragma once
#include <string>
#include <models/RemoteUser.h>
#include <models/UserModelORM.h>
#include <models/PublicKeys.h>
#ifndef USERMODEL_H
#define USERMODEL_H

// This struct is used for local user data storage.
// i.e. during runtime the logged-in user data is stored here.
struct UserModel: RemoteUser, PublicKeys {
    // Local Database ID
    int id;

    // Ed25519 identity key fields
    std::string ed25519_identity_key_private_enc;
    std::string ed25519_identity_key_private_nonce;

    // X25519 identity key fields
    std::string x25519_identity_key_private_enc;
    std::string x25519_identity_key_private_nonce;

    // Signed prekey fields
    std::string signed_prekey_private_enc;
    std::string signed_prekey_private_nonce;

    // One-time prekeys as JSON
    std::string opks_json;

    // #Operator Overloading
    // Overloads the assignment operator to copy data from UserModelORM
    // Demonstrates custom behavior for operator= with user-defined types
    UserModel& operator=(const UserModelORM& orm) {
        this->uuid = orm.uuid;
        this->username = orm.username;
        this->email = orm.email;
        this->salt = orm.salt;
        this->ed25519_identity_key_public = orm.ed25519_identity_key_public;
        this->ed25519_identity_key_private_enc = orm.ed25519_identity_key_private_enc;
        this->ed25519_identity_key_private_nonce = orm.ed25519_identity_key_private_nonce;
        this->x25519_identity_key_public = orm.x25519_identity_key_public;
        this->x25519_identity_key_private_enc = orm.x25519_identity_key_private_enc;
        this->x25519_identity_key_private_nonce = orm.x25519_identity_key_private_nonce;
        this->signed_prekey_public = orm.signed_prekey_public;
        this->signed_prekey_signature = orm.signed_prekey_signature;
        this->signed_prekey_private_enc = orm.signed_prekey_private_enc;
        this->signed_prekey_private_nonce = orm.signed_prekey_private_nonce;
        this->opks_json = orm.opks_json;
        this->id = orm.id;
        return *this;
    }

    // #Explicit Constructor (call by const reference)
    // Creates a new UserModel from a UserModelORM instance
    // Uses this pointer implicitly through the assignment operator
    explicit UserModel(const UserModelORM& orm) {
        *this = orm; // Uses the assignment operator
    }

    // #Default Constructor
    // Creates a new UserModel with default values
    UserModel() = default;
};
#endif //USERMODEL_H
