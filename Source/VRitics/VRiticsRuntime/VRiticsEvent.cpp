﻿// Copyright 2024 Vritics sp. z o.o.

#include "VRiticsEvent.h"

VRiticsEvent::VRiticsEvent()
{
}

VRiticsEvent::VRiticsEvent(FString name, FVector3f position, bool isSuccessful)
{
	Name = name;
	Position = position;
	bIsSuccessful = isSuccessful;
	DateTime = FDateTime::UtcNow();
}

VRiticsEvent::~VRiticsEvent()
{
}

FString VRiticsEvent::ToJsonFormat()
{
	FString json = "{";
	json.Append("\"object_id\":\"");
	json.Append(Name);
	json.Append ("\",\n");
	json.Append ("\"is_hit\":");
	json.Append (bIsSuccessful ? "true" : "false");
	json.Append (",\n");
	json.Append ("\"raycast_start\":");
	json.Append ("{\"x\":");
	FString FValue = FString::SanitizeFloat(Position.X);
	json.Append (FValue);
	json.Append (",\"y\":");
	FValue = FString::SanitizeFloat(Position.Y);
	json.Append (FValue);
	json.Append (",\"z\":");
	FValue = FString::SanitizeFloat(Position.Z);
	json.Append (FValue);
	json.Append ("}");
	json.Append (",\n");
	json.Append ("\"raycast_end\":");
	json.Append ("{\"x\":");
	FValue = FString::SanitizeFloat(Position.X);
	json.Append (FValue);
	json.Append (",\"y\":");
	FValue = FString::SanitizeFloat(Position.Y);
	json.Append (FValue);
	json.Append (",\"z\":");
	FValue = FString::SanitizeFloat(Position.Z);
	json.Append (FValue);
	json.Append ("},\n");
	json.Append ("\"created_at\":");
	json.Append ("\"");
	json.Append (DateTime.ToString (TEXT("%Y-%m-%d %H:%M:%S")));
	json.Append ("\"\n");
	json.Append ("}");
	return json;
}