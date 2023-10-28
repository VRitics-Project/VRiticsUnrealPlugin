// Fill out your copyright notice in the Description page of Project Settings.


#include "VRiticsEvent.h"


VRiticsEvent::VRiticsEvent()
{
}

VRiticsEvent::VRiticsEvent(FString name, FVector3f position, bool isSuccessful)
{
	Name = name;
	Position = position;
	bIsSuccessful = isSuccessful;
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
	json.Append ("}");
	json.Append ("\"created_at\":");
	json.Append ("\"");
	json.Append ("2023-10-17 21:37:69");
	json.Append ("\"\n");
	json.Append ("}");
	return json;
}