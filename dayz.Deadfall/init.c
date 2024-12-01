void main()
{
	// Support Dynamic Weather Plugin mod
	//INIT WEATHER BEFORE ECONOMY INIT------------------------
	string weatherConfig = "$mission:weather.json";
	if (FileExist(weatherConfig))
	{
		Weather weather = g_Game.GetWeather();
		weather.MissionWeather(false);    // false = use weather controller from Weather.c
	}

	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//Loot spawn Creator
	//GetCEApi().ExportProxyData(vector.Zero, 100000); //Loot
	//GetCEApi().ExportClusterData(); //Fruit

	// fixed date
	int year, month, day, hour, minute;
	GetGame().GetWorld().GetDate( year, month, day, hour, minute );

    if ( month != 10 )
    {
    	year = 2021;
        month = 10;
        day = 1;
		
		GetGame().GetWorld().SetDate( year, month, day, hour, minute );
	}
}

class CustomMission: MissionServer
{
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.45, 0.65 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
		Class.CastTo( m_player, playerEnt );

		GetGame().SelectPlayer( identity, m_player );

		return m_player;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		EntityAI itemClothing;
		EntityAI itemEnt;
		ItemBase itemBs;
		float rand;

		itemClothing = player.FindAttachmentBySlotName( "Body" );
		if ( itemClothing )
		{
			SetRandomHealth( itemClothing );
			
			// rag
			itemEnt = itemClothing.GetInventory().CreateInInventory( "Rag" );
			if ( Class.CastTo( itemBs, itemEnt ) )
			{
				SetRandomHealth( itemEnt );
				itemBs.SetQuantity( 4 );
				itemBs.SetCleanness( 1 );
			}
			player.SetQuickBarEntityShortcut( itemEnt, 0 );

			// food
			rand = Math.RandomFloatInclusive( 0.0, 1.0 );
			if ( rand < 0.35 )
				itemEnt = player.GetInventory().CreateInInventory( "Apple" );
			else if ( rand > 0.65 )
				itemEnt = player.GetInventory().CreateInInventory( "Pear" );
			else
				itemEnt = player.GetInventory().CreateInInventory( "Plum" );
			SetRandomHealth( itemEnt );

			// map
			//itemClothing.GetInventory().CreateInInventory( "ChernarusMap" );
		}
		
		itemClothing = player.FindAttachmentBySlotName( "Legs" );
		if ( itemClothing )
			SetRandomHealth( itemClothing );
		
		itemClothing = player.FindAttachmentBySlotName( "Feet" );
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}