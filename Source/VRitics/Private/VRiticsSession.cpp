#include "VRiticsSession.h"

#include "HttpModule.h"
#include "VRiticsSetup.h"

TArray<VRiticsSession> VRiticsSession::CurrentSessions;
class FHttpModule;

VRiticsSession::VRiticsSession()
{
	// Events = TArray<VRiticsEvent>();
}

VRiticsSession::~VRiticsSession()
{
}

VRiticsSession::VRiticsSession(FString name)
{
	Name = name;

}

void VRiticsSession::AddSession(FString name)
{
	CurrentSessions.Add(VRiticsSession(name));
}

void VRiticsSession::RegisterEvent(FString name, FVector3f position , bool isSuccessful)
{
	for (auto Session : CurrentSessions)
	{
		Session.Events.Add(VRiticsEvent(name, position, isSuccessful));
	}
}

void VRiticsSession::SendSessions()
{
	for (auto currentSession : CurrentSessions)
	{
		FString RequestContent = "{";

		RequestContent.Append ("\"player_id\": \"");
		RequestContent.Append (UVRiticsSetup::PlayerID);
		RequestContent.Append ("\",\n");

		RequestContent.Append ("\"session_name\": \"");
		RequestContent.Append (currentSession.Name);
		RequestContent.Append ("\",\n");

		RequestContent.Append ("\"unity_scene_name\": \"");
		RequestContent.Append (currentSession.SceneName);
		RequestContent.Append ("\",\n");

		RequestContent.Append ("\"data\": [\n");
		for (int i = 0; i < currentSession.Events.Num(); i++) {
			RequestContent.Append (currentSession.Events[i].ToJsonFormat ());
			if (i < currentSession.Events.Num() - 1)
				RequestContent.Append (",\n");
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
		pRequest->SetHeader(TEXT("Authorization"), TEXT("Bearer"+UVRiticsSetup::Token));
		pRequest->SetContentAsString(RequestContent);

		pRequest->SetURL(uri);

		pRequest->OnProcessRequestComplete().BindLambda(
		    [&](
		        FHttpRequestPtr pRequest,
		        FHttpResponsePtr pResponse,
		        bool connectedSuccessfully) mutable {

		    if (connectedSuccessfully) {
		    	UE_LOG(LogTemp, Error, TEXT("Succsess."));
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
	}
}
