
#include "gtest/gtest.h"

#include <arkClient.h>

#include <iostream>

////////////////////////////////////////////////////////////////////////////////
constexpr auto DEFAULT_PEER_APN = "https://wallets.ark.io";
constexpr auto ADN_PEER = "167.114.29.55";
constexpr auto ADN_API_PORT = 4003;

////////////////////////////////////////////////////////////////////////////////
TEST(api_connection, constructor_default) {
  Connection<Api> connection;

  const auto result = connection.getPeer();

  ASSERT_TRUE(strcmp(result.c_str(), DEFAULT_PEER_ADN) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_connection, constructor_custom_peer) {
  Connection<Api> connection(DEFAULT_PEER_APN);

  const auto result = connection.getPeer();

  ASSERT_TRUE(strcmp(result.c_str(), DEFAULT_PEER_APN) == 0);
}

TEST(api_connection, constructor_ip_port) {
  Connection<Api> connection(ADN_PEER, ADN_API_PORT);

  constexpr auto expected = "167.114.29.55:4003";

  const auto result = connection.getPeer();

  printf("\n\nresult: %s", result.c_str());
  ASSERT_TRUE(strcmp(result.c_str(), expected) == 0);
}
