#include "pch.h"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;

int main()
{
    Socket^ s = gcnew Socket(AddressFamily::InterNetwork, SocketType::Dgram, ProtocolType::Udp);
    IPAddress^ broadcast = IPAddress::Parse("127.0.0.1");
    String^ slovo = "brojke";
    array<unsigned char>^ sendbuf = Encoding::ASCII->GetBytes(slovo);
    IPEndPoint^ ep = gcnew IPEndPoint(broadcast, 5004);
    s->SendTo(sendbuf, ep);
    Console::WriteLine("Message was sent");
}