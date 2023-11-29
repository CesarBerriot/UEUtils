#pragma once

#pragma region Checks
#define checkValidPtr(ptr) checkf(ptr, L"pointer '%hs' in instance of class '%ls' was invalid !", #ptr, *ThisClass::StaticClass()->GetName())

#define checkIsBlueprint() checkf(GetClass() != ThisClass::StaticClass(), L"class %ls Instance Initialization : failed IsBlueprint check", *ThisClass::StaticClass()->GetName());
#define checkIsWidgetBlueprint() checkf(GetClass() != ThisClass::StaticClass(), L"%ls::NativeConstruct : failed IsBlueprint check", *ThisClass::StaticClass()->GetName());
#define checkIsActorBlueprint() checkf(GetClass() != ThisClass::StaticClass(), L"%ls::BeginPlay : failed IsBlueprint check", *ThisClass::StaticClass()->GetName());
#define checkIsGameInstanceBlueprint() checkf(GetClass() != ThisClass::StaticClass(), L"%ls::Init : failed IsBlueprint check", *ThisClass::StaticClass()->GetName());
#define checkIsGameStateBlueprint checkIsActorBlueprint
#define checkIsGameModeBaseBlueprint() checkf(GetClass() != ThisClass::StaticClass(), L"%ls::InitGame : failed IsBlueprint check", *ThisClass::StaticClass()->GetName());
#pragma endregion Checks

#define DEFINE_INLINE_MEMBER_GETTER(NameLowerCasePrefix, NameUpperCasePrefix, Name) FORCEINLINE decltype(NameLowerCasePrefix##Name) const & Get##NameUpperCasePrefix##Name() const { return  NameLowerCasePrefix##Name; }


#pragma region Log
#if !UE_BUILD_SHIPPING
	#define __get_game_instance PartyGameUtils::GetGameInstanceChecked(GetWorld())
	
	#define LOG __get_game_instance.Log
	#define LOGF(Color, Format, ...) __get_game_instance.Logf(ELogColor::Color, Format, __VA_ARGS__)
	#define LOG_SEPARATOR __get_game_instance.LogSeparator
	
	#define __get_game_instance_custom_world(World) PartyGameUtils::GetGameInstanceChecked(World)
	
	#define LOG_EX(World, ...) __get_game_instance_custom_world(World).Log(__VA_ARGS__)
	#define LOGF_EX(World, Color, Format, ...) __get_game_instance_custom_world(World).Logf(ELogColor::Color, Format, __VA_ARGS__)
	#define LOG_SEPARATOR_EX(World, ...) __get_game_instance_custom_world(World).LogSeparator(__VA_ARGS__)
#else
	#define LOG(...) 				0
	#define LOGF(...)				0
	#define LOG_SEPARATOR(...)		0
	#define LOG_EX(...)				0
	#define LOGF_EX(...)			0
	#define LOG_SEPARATOR_EX(...)	0
#endif
#pragma endregion Log
#pragma region IF_DEFINED
// IF_UE_BUILD_SHIPPING(x, y) expands to x if UE_BUILD_SHIPPING is set, otherwise expands to y
#if UE_BUILD_SHIPPING
	#define IF_UE_BUILD_SHIPPING(x, y) x
#else
	#define IF_UE_BUILD_SHIPPING(x, y) y
#endif
#pragma endregion IF_DEFINED
