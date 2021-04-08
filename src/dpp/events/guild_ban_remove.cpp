#include <dpp/discord.h>
#include <dpp/event.h>
#include <string>
#include <iostream>
#include <fstream>
#include <dpp/discordclient.h>
#include <dpp/discord.h>
#include <dpp/cache.h>
#include <dpp/stringops.h>
#include <nlohmann/json.hpp>
#include <dpp/discordevents.h>

using json = nlohmann::json;

void guild_ban_remove::handle(class DiscordClient* client, json &j, const std::string &raw) {
	if (client->creator->dispatch.guild_ban_remove) {
		json &d = j["d"];
		dpp::guild_ban_remove_t gbr(raw);
		gbr.unbanning_guild = dpp::find_guild(SnowflakeNotNull(&d, "guild_id"));
		gbr.unbanned = dpp::user().fill_from_json(&(d["user"]));
		client->creator->dispatch.guild_ban_remove(gbr);
	}
}

