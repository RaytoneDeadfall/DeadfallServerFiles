# Deadfall Server Files

This repo should contain everything needed for running a Deadfall server.  It contains mission folder,
server profile config files (found in `extras/`), and CE files for further editing of the economy.

Note: Server profiles directory is specified with the `-profiles=` launch parameter in the server startup
script.

## Deadfall Economy 

You're welcome to modify these files anyway you'd like, but keep in mind that Deadfall was designed
to be an adventure-style map.  Base building and vehicles/helicopters are not recommended and are disabled.
The roads have not been tested for vehicles and helicopters would allow players to see and get through 
areas/gaps of the terrain that they are not intended to.

## Additional Mods and Configuration

The following mod profile config files are provided to enrich the overall Deadfall experience.

### Use CfgGameplayFile (recommended)

To enable the usage of this file, set a parameter "enableCfgGameplayFile = 1;" in your server.cfg file.  This
file controls the world temperatures, which is important since Deadfall has cold zones.

### Stargate Teleporters Complete (required)

Deadfall has a hard dependency on the Stargate Teleport mod, as some of the terrain is inaccessible without
teleportation.

You can find the teleport configuration file customized for Deadfall at `extras/CBD_PortalTeleporterSystem.json`.  
This file should be placed in your server profile directory to enable the teleporters.

For example, if your profiles directory is set to `profiles`, this file location will be:

```
profiles/CBD_PortalTeleporterSystem.json
```

Stargate Teleporters Complete by Chris
https://steamcommunity.com/sharedfiles/filedetails/?id=2933015619

### SpawnerBubaku (optional)

To spawn AI in many underground and difficult-to-place areas, there is an included configuration file at
`extras/SpawnerBubaku/SpawnerBubakuV2.jsonn`.  This must be placed in your server profile directory.

For example, if your profiles directory is set to `profiles`, this file location will be:

```
profiles/SpawnerBubaku/SpawnerBubakuV2.json
```

You can customize this file to spawn whatever creatures you'd like.

SpawnerBubaku by Hunterz
https://steamcommunity.com/sharedfiles/filedetails/?id=2482312670

Note: This mod can be run server-side only.

### GasMasksOnly (recommended)

Deadfall has a large toxic zone at the passage.  It is recommended to use the GasMasksOnly to make it
easier for players to get through this area.  Without this mod, you'll need to add the NBC gear to your
economy via `db/types.xml`.

GasMasksOnly by Crocodoc
https://steamcommunity.com/sharedfiles/filedetails/?id=2621103156


### Custom Labyrinth Monsters (optional)

There is an event named `InfectedMonster` which you can use to customize spawning a unique creature or
mutant in the labyrinth.  To do this, simply add children to this event.  Only 1 creature will spawn by default.

For example, set the children elements to the `InfectedMonster` event:

```
<children>
    <child lootmax="5" lootmin="0" max="0" min="100" type="SMCS_Mutant" />
</children>
```

Note: You can also avoid editing mission files directly by overriding them in your own types.xml and events.xml
files.  Doing this makes it easier to maintain your customizations.

Read more: https://community.bistudio.com/wiki/DayZ:Central_Economy_mission_files_modding
