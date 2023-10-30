#include "VRiticsSession.h"

#include "HttpModule.h"
#include "VRiticsSetup.h"
#include "Interfaces/IHttpResponse.h"

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

void VRiticsSession::RegisterEvent(FString name, FVector3f position , bool isSuccessful)
{
	for (int i = 0; i < CurrentSessions.Num(); ++i)
	{
		CurrentSessions[i].Events.Add(VRiticsEvent(name, position, isSuccessful));
	}
}

void VRiticsSession::SendSessions()
{
	for (int i = CurrentSessions.Num()-1; i >= 0; i--)
	{
		FString RequestContent = "{";
		RequestContent.Append ("\"player_id\": \"");
		RequestContent.Append (UVRiticsSetup::PlayerID);
		RequestContent.Append ("\",\n");

		RequestContent.Append ("\"session_name\": \"");
		RequestContent.Append (CurrentSessions[i].Name);
		RequestContent.Append ("\",\n");

		RequestContent.Append ("\"unity_scene_name\": \"");
		RequestContent.Append (CurrentSessions[i].SceneName);
		RequestContent.Append ("\",\n");

		RequestContent.Append ("\"data\": [\n");
		for (int j = CurrentSessions[i].Events.Num()-1; j >= 0; j--) {
			RequestContent.Append (CurrentSessions[i].Events[j].ToJsonFormat ());
			if (j > 0)
				RequestContent.Append (",\n");
			CurrentSessions[i].Events.RemoveAt(j);
		}
		RequestContent.Append ("],\n");
		RequestContent.Append (" \"custom_data\": {\n");
		RequestContent.Append ("\"test\": 123,\n");
		RequestContent.Append ("\"test_2\":true\n");
		RequestContent.Append ("}\n");
		RequestContent.Append ("}\n");

		FString uri = "http://vr-collector.server306419.nazwa.pl/api/apps/"+UVRiticsSetup::AppID+"/raycasts";
		
		FHttpModule& httpModule = FHttpModule::Get();
		
		TSharedRef<IHttpRequest, ESPMode::ThreadSafe> pRequest = httpModule.CreateRequest();

		pRequest->SetVerb(TEXT("POST"));
		pRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
		pRequest->SetHeader(TEXT("Authorization"), TEXT("Bearer "+UVRiticsSetup::Token));
		pRequest->SetContentAsString(RequestContent);
		UE_LOG(LogTemp, Display, TEXT("%s"), *RequestContent);

		pRequest->SetURL(uri);

		pRequest->OnProcessRequestComplete().BindLambda(
		    [&](
		        FHttpRequestPtr pRequest,
		        FHttpResponsePtr pResponse,
		        bool connectedSuccessfully) mutable {

		    if (connectedSuccessfully) {
		    	auto response = pResponse->GetContentAsString();
		    	UE_LOG(LogTemp, Display, TEXT("%s"), *response);
		    }
		    else {
		        switch (pRequest->GetStatus()) {
		        case EHttpRequestStatus::Failed_ConnectionError:
		            UE_LOG(LogTemp, Error, TEXT("Connection failed."));
		        default:
		            UE_LOG(LogTemp, Error, TEXT("Request failed."));
		        }
		    }
		});

		pRequest->ProcessRequest();
		CurrentSessions.RemoveAt(i);
	}
}
