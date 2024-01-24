// Copyright 2024 Vritics sp. z o.o.

#include "VRiticsSession.h"

#include "HeadMountedDisplayFunctionLibrary.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "VRitics.h"

TArray<VRiticsSession> VRiticsSession::CurrentSessions;
class FHttpModule;

VRiticsSession::VRiticsSession()
{
}

VRiticsSession::~VRiticsSession()
{
}

VRiticsSession::VRiticsSession(FString name)
{
	Name = name;
	SceneName = "SceneWithEvents";
}

void VRiticsSession::AddSession(FString name)
{
	CurrentSessions.Add(VRiticsSession(name));
}

void VRiticsSession::RegisterEvent(FString name, FVector3f position, bool isSuccessful)
{
	for (int i = 0; i < CurrentSessions.Num(); ++i)
	{
		CurrentSessions[i].Events.Add(VRiticsEvent(name, position, isSuccessful));
	}
}

FString ExtractTitleFromHtml(const FString& HtmlString)
{
	const FRegexPattern TitlePattern(TEXT("<title>(.*?)</title>"));

	FRegexMatcher TitleMatcher(TitlePattern, HtmlString);
	if (TitleMatcher.FindNext())
	{
		// Extract the content of the <title> tag
		FString TitleContent = TitleMatcher.GetCaptureGroup(1);
		return TitleContent;
	}

	// Return an empty string if <title> tag is not found
	return FString();
}

void VRiticsSession::SendSession(const FString& PlayerId, const FString& AppId, const FString& Token,
                                 VRiticsSession& Session, const void (*Func)(const FString& Response))
{
	FString RequestContent = "{";
	RequestContent.Append("\"player_id\": \"");
	RequestContent.Append(PlayerId);
	RequestContent.Append("\",\n");

	RequestContent.Append("\"session_name\": \"");
	RequestContent.Append(Session.Name);
	RequestContent.Append("\",\n");

	RequestContent.Append("\"unity_scene_name\": \"");
	RequestContent.Append(Session.SceneName);
	RequestContent.Append("\",\n");

	RequestContent.Append("\"device\": \"");
	FName DeviceName = UHeadMountedDisplayFunctionLibrary::GetHMDDeviceName();
	RequestContent.Append(DeviceName.ToString());
	RequestContent.Append("\",\n");

	RequestContent.Append("\"data\": [\n");
	for (int j = Session.Events.Num() - 1; j >= 0; j--)
	{
		RequestContent.Append(Session.Events[j].ToJsonFormat());
		if (j > 0)
		{
			RequestContent.Append(",\n");
		}
		Session.Events.RemoveAt(j);
	}
	RequestContent.Append("],\n");
	RequestContent.Append(" \"custom_data\": {\n");
	RequestContent.Append("\"test\": 123,\n");
	RequestContent.Append("\"test_2\":true\n");
	RequestContent.Append("}\n");
	RequestContent.Append("}\n");

	FString uri = "http://vr-collector.server306419.nazwa.pl/api/apps/" + AppId + "/raycasts";

	FHttpModule& httpModule = FHttpModule::Get();

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> pRequest = httpModule.CreateRequest();

	pRequest->SetVerb(TEXT("POST"));
	pRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	pRequest->SetHeader(TEXT("Authorization"), TEXT("Bearer "+Token));
	pRequest->SetContentAsString(RequestContent);
	UE_LOG(LogTemp, Display, TEXT("%s"), *RequestContent);

	pRequest->SetURL(uri);

	pRequest->OnProcessRequestComplete().BindLambda(
		[&, Func](
		FHttpRequestPtr pRequest,
		FHttpResponsePtr pResponse,
		bool connectedSuccessfully) mutable
		{
			FString Response = "";
			if (connectedSuccessfully)
			{
				Response = ExtractTitleFromHtml(pResponse->GetContentAsString());
			}
			else
			{
				switch (pRequest->GetStatus())
				{
				case EHttpRequestStatus::Failed_ConnectionError:
					Response = TEXT("Connection failed.");
					break;
				default:
					Response = TEXT("Request failed.");
				}
			}
			if (Func != nullptr)
			{
				Func(Response);
			}
		});

	pRequest->ProcessRequest();
}

void VRiticsSession::SendSessions()
{
	for (int i = CurrentSessions.Num() - 1; i >= 0; i--)
	{
		CurrentSessions[i].SendSession(FVRiticsModule::PlayerID, FVRiticsModule::AppID, FVRiticsModule::Token,
		                               CurrentSessions[i], nullptr);
		CurrentSessions.RemoveAt(i);
	}
}

void VRiticsSession::TestSessions(const FString& AppId, const FString& Token,
                                  const void (*Func)(const FString& response))
{
	VRiticsSession* TestSession = new VRiticsSession("TestSession");
	TestSession->Events.Add(VRiticsEvent("TestEvent", FVector3f::Zero(), true));
	TestSession->SendSession("Test", AppId, Token, *TestSession, Func);
	delete TestSession;
}
