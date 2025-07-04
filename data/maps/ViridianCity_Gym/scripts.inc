.set LOCALID_GIOVANNI, 8

ViridianCity_Gym_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Giovanni::
	famechecker FAMECHECKER_GIOVANNI, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_GIOVANNI, ViridianCity_Gym_Text_GiovanniIntro, ViridianCity_Gym_Text_GiovanniDefeat, ViridianCity_Gym_EventScript_DefeatedGiovanni, NO_MUSIC
	goto_if_unset FLAG_GOT_TM26_FROM_GIOVANNI, ViridianCity_Gym_EventScript_GiveTM26
	msgbox ViridianCity_Gym_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_GIOVANNI
	fadescreen FADE_FROM_BLACK
	release
	end

ViridianCity_Gym_EventScript_DefeatedGiovanni::
	famechecker FAMECHECKER_GIOVANNI, 3
	setflag FLAG_HIDE_MISC_KANTO_ROCKETS
	setflag FLAG_DEFEATED_LEADER_GIOVANNI
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_CERULEAN_CAVE_GUARD
	setvar VAR_MAP_SCENE_ROUTE22, 3
	set_gym_trainers 8
	goto ViridianCity_Gym_EventScript_GiveTM26
	end

ViridianCity_Gym_EventScript_GiveTM26::
	msgbox ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis
	checkitemspace ITEM_TM26
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_Gym_EventScript_NoRoomForTM26
	giveitem_msg ViridianCity_Gym_Text_ReceivedTM26FromGiovanni, ITEM_TM26
	setflag FLAG_GOT_TM26_FROM_GIOVANNI
	msgbox ViridianCity_Gym_Text_ExplainTM26
	release
	end

ViridianCity_Gym_EventScript_NoRoomForTM26::
	msgbox ViridianCity_Gym_Text_YouDoNotHaveSpace
	release
	end

ViridianCity_Gym_EventScript_Jason::
	trainerbattle_single TRAINER_TAMER_JASON, ViridianCity_Gym_Text_JasonIntro, ViridianCity_Gym_Text_JasonDefeat
	msgbox ViridianCity_Gym_Text_JasonPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Cole::
	trainerbattle_single TRAINER_TAMER_COLE, ViridianCity_Gym_Text_ColeIntro, ViridianCity_Gym_Text_ColeDefeat
	msgbox ViridianCity_Gym_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Atsushi::
	trainerbattle_single TRAINER_BLACK_BELT_ATSUSHI, ViridianCity_Gym_Text_AtsushiIntro, ViridianCity_Gym_Text_AtsushiDefeat
	msgbox ViridianCity_Gym_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Kiyo::
	trainerbattle_single TRAINER_BLACK_BELT_KIYO, ViridianCity_Gym_Text_KiyoIntro, ViridianCity_Gym_Text_KiyoDefeat
	msgbox ViridianCity_Gym_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Takashi::
	trainerbattle_single TRAINER_BLACK_BELT_TAKASHI, ViridianCity_Gym_Text_TakashiIntro, ViridianCity_Gym_Text_TakashiDefeat
	msgbox ViridianCity_Gym_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Samuel::
	trainerbattle_single TRAINER_COOLTRAINER_SAMUEL, ViridianCity_Gym_Text_SamuelIntro, ViridianCity_Gym_Text_SamuelDefeat
	msgbox ViridianCity_Gym_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Yuji::
	trainerbattle_single TRAINER_COOLTRAINER_YUJI, ViridianCity_Gym_Text_YujiIntro, ViridianCity_Gym_Text_YujiDefeat
	msgbox ViridianCity_Gym_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Warren::
	trainerbattle_single TRAINER_COOLTRAINER_WARREN, ViridianCity_Gym_Text_WarrenIntro, ViridianCity_Gym_Text_WarrenDefeat
	msgbox ViridianCity_Gym_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_GIOVANNI, ViridianCity_Gym_EventScript_GymGuyPostVictory
	msgbox ViridianCity_Gym_Text_GymGuyAdvice
	release
	end

ViridianCity_Gym_EventScript_GymGuyPostVictory::
	famechecker FAMECHECKER_GIOVANNI, 4
	msgbox ViridianCity_Gym_Text_GymGuyPostVictory
	release
	end

ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end
