#pragma once

// ClientSocket 명령 대상

class ClientSocket : public CSocket
{
public:
	ClientSocket();
	virtual ~ClientSocket();

	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
};


