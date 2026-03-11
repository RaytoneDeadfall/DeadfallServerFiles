# Deadfall Server Files

This repo contains everything needed to run a Deadfall server:

- **`dayz.Deadfall/`** — The mission folder. This entire folder is placed on your server where DayZ expects its mission files.
- **`CE/`** — Central Economy (CE) files.  These files supplement the mission folder and can be edited to tune the economy. (completely optional)
- **`extras/`** — Mod configuration files for your server profile directory (see below).

> **What is the server profile directory?**  
> It is the folder specified by the `-profiles=` launch parameter in your server startup script (e.g., `-profiles=profiles`). DayZ reads mod config files from this directory at startup. If you are unsure what yours is set to, check your startup script or server control panel.

## Quick Start

Follow these steps in order to get the server running correctly.

**Required**

1. Copy the `dayz.Deadfall/` folder to your server's mission directory.
2. Install the **Stargate Teleporters Complete** mod and copy `extras/CBD_PortalTeleporterSystem.json` to your server profile directory (see [below](#stargate-teleporters-complete-required)). Players cannot access certain parts of the map without this mod.
3. Add `enableCfgGameplayFile = 1;` to your `server.cfg` (see [below](#use-cfggameplayfile-recommended)) — required for cold zone temperatures to work correctly.

**Recommended**

4. Install the **GasMasksOnly** mod (see [below](#gasmasks-only-recommended)) to make the toxic passage zone playable without NBC gear.
5. Install the **SpawnerBubaku** mod and copy `extras/SpawnerBubaku/SpawnerBubakuV2.json` to a `SpawnerBubaku` subfolder in your server profile directory (see [below](#spawnerbubaku-recommended)). Spawns additional zombies and creatures in areas that are difficult to populate with the standard CE system.

---

## Deadfall Economy

You are welcome to modify the mission files however you like, but keep in mind that Deadfall was designed as an adventure/exploration map. Base building and vehicles/helicopters are **not recommended** and are disabled by default:

- **Vehicles** — The roads have not been tested for vehicle travel.
- **Helicopters** — Players could use them to bypass terrain that is intentionally inaccessible, breaking the intended experience.
- **Base Building** — Flags, tools, nails and other base-building supplies are not configured to spawn by default.

---

## Additional Mods and Configuration

The following mod profile config files are included in `extras/` to enrich the Deadfall experience with additional mods.

### Use CfgGameplayFile *(recommended)*

`cfggameplay.json` controls world temperatures. This is important because Deadfall has cold zones that affect player survival. Without this enabled, temperatures may not behave as designed.

To enable it, add the following line to your `server.cfg` at the root level (not inside any block):

```
enableCfgGameplayFile = 1;
```

The config file itself is already included in the mission folder at `dayz.Deadfall/cfggameplay.json` — no additional file copying is needed.

### Stargate Teleporters Complete *(required)*

Deadfall has a hard dependency on this mod. Certain areas of the map are physically inaccessible without teleportation, so the player experience **will not be complete as intended** without it.

**Setup:**  
Copy `extras/CBD_PortalTeleporterSystem.json` to your server profile directory.

For example, if your profiles directory is named `profiles`:

```
profiles/CBD_PortalTeleporterSystem.json
```

> **Stargate Teleporters Complete** by Chris  
> https://steamcommunity.com/sharedfiles/filedetails/?id=2933015619

### SpawnerBubaku *(recommended)*

This mod spawns AI creatures in underground areas and other locations that are difficult to populate using DayZ's standard CE system. An included configuration file pre-sets spawns tuned for Deadfall.

**Setup:**  
Copy `extras/SpawnerBubaku/SpawnerBubakuV2.json` to your server profile directory, inside a `SpawnerBubaku` subfolder:

```
profiles/SpawnerBubaku/SpawnerBubakuV2.json
```

You can edit this file to change which creatures spawn and at what quantities.

> **SpawnerBubaku** by Hunterz  
> https://steamcommunity.com/sharedfiles/filedetails/?id=2482312670

> **Note:** This mod can be run as a server-side mod — clients do not need to install it.

### GasMasks Only *(recommended)*

Deadfall has a large toxic zone at the passage. This mod makes gas masks the primary protective option, which is simpler for players than sourcing a full NBC suit.

Without this mod, you will need to manually add NBC gear to your loot economy by editing `dayz.Deadfall/db/types.xml`.

> **GasMasksOnly** by Crocodoc  
> https://steamcommunity.com/sharedfiles/filedetails/?id=2621103156

### Custom Labyrinth Monsters *(optional)*

There is a pre-defined event named `InfectedMonster` in `dayz.Deadfall/db/events.xml` that controls what creature (if any) spawns in the labyrinth. By default it spawns 1 type of creature, but no specific creature type is set — you must add children to activate it.

**Example** — spawning a custom mutant:

```xml
<children>
    <child lootmax="5" lootmin="0" max="1" min="1" type="Your_Creature" />
</children>
```

**Pro Tip:** Instead of editing the mission files directly, you can override `types.xml` and `events.xml` using your own server-side files. This keeps your customizations separate and makes future updates easier to apply.

Read more: https://community.bistudio.com/wiki/DayZ:Central_Economy_mission_files_modding
