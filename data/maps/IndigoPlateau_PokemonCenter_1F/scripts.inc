.set LOCALID_DOOR_GUARD, 4

IndigoPlateau_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

IndigoPlateau_PokemonCenter_1F_OnTransition::
	setrespawn SPAWN_INDIGO_PLATEAU
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	call_if_eq VAR_RESULT, TRUE, IndigoPlateau_PokemonCenter_1F_EventScript_CheckBlockDoor
	end

IndigoPlateau_PokemonCenter_1F_EventScript_CheckBlockDoor::
	goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, EventScript_Return
	setobjectxyperm LOCALID_DOOR_GUARD, 4, 2
	return

IndigoPlateau_PokemonCenter_1F_EventScript_DoorGuard::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, IndigoPlateau_PokemonCenter_1F_EventScript_CheckDifficulty
	msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_CheckDifficulty::
	goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, IndigoPlateau_PokemonCenter_1F_EventScript_AskLowerDifficulty
	msgbox IndigoPlateau_PokemonCenter_1F_Text_AskIncreaseDifficulty
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, IndigoPlateau_PokemonCenter_1F_EventScript_IncreaseDifficulty
	msgbox IndigoPlateau_PokemonCenter_1F_Text_KeepCurrentDifficulty
	waitmessage
	closemessage
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_IncreaseDifficulty::
	setflag FLAG_SYS_CAN_LINK_WITH_RS
	msgbox IndigoPlateau_PokemonCenter_1F_Text_IncreasedDifficulty
	waitmessage
	closemessage
	call EventScript_ResetEliteFourEnd
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_AskLowerDifficulty::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_AskDecreaseDifficulty
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, IndigoPlateau_PokemonCenter_1F_EventScript_DecreaseDifficulty
	msgbox IndigoPlateau_PokemonCenter_1F_Text_KeepCurrentDifficulty
	waitmessage
	closemessage
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_DecreaseDifficulty::
	clearflag FLAG_SYS_CAN_LINK_WITH_RS
	msgbox IndigoPlateau_PokemonCenter_1F_Text_DecreasedDifficulty
	waitmessage
	closemessage
	call EventScript_ResetEliteFourEnd
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_GymGuy::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice, MSGBOX_NPC
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Clerk::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart IndigoPlateau_PokemonCenter_1F_Items
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
IndigoPlateau_PokemonCenter_1F_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end
