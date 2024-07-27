# Deadfall Server Files

This repo should contain everything needed for running a Deadfall server.  It contains mission folder,
server profile/config files (found in `extras/`), and CE files for further editing of the economy.


## Additional Mods

The following mods and profile config files are used to enrich the overall Deadfall experience.

### Stargate Teleporter (required)

Deadfall has a hard dependency on the Stargate Teleport mod, as some of the terrain is inaccessible without
teleportation.  In the future, this might be implemented internally, but for now we will use this mod.

Stargate Teleporters Complete by Chris
https://steamcommunity.com/sharedfiles/filedetails/?id=2933015619

You can find the teleport configuration file customized for Deadfall at `extras/CBD_PortalTeleporterSystem.json`.  
This file should be placed in your server profile directory to enable the teleporters.


### GasMasksOnly (recommended)

Deadfall has a large toxic zone at the passage.  It is recommended to use the GasMasksOnly to make it
easier for players to get through this area.  Without this mod, you'll need to add the NBC gear to your
economy via `db/types.xml`.

GasMasksOnly by Crocodoc
https://steamcommunity.com/sharedfiles/filedetails/?id=2621103156


### SpawnerBubaku (server mod only)

To spawn AI in many underground and difficult-to-place areas, there is an included configuration file at
`extras/SpawnerBubaku/SpawnerBubaku.json`.

SpawnerBubaku by Hunterz
https://steamcommunity.com/sharedfiles/filedetails/?id=2482312670
