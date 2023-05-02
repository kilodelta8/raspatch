/*
*
*
*/
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <iostream>

typedef websocketpp::server<websocketpp::config::asio> server;

int main() {
    server my_server;
    my_server.init_asio();

    my_server.set_message_handler([](websocketpp::connection_hdl hdl, server::message_ptr msg) {
        std::cout << "Received sensor data: " << msg->get_payload() << std::endl;
    });

    my_server.listen(9002);
    my_server.start_accept();

    while (true) {
        // read sensor data and send it over WebSocket connection
        my_server.send("sensor_data");
    }

    return 0;
}
