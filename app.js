const socket = io('http://localhost:9002');

socket.on('connect', () => {
    console.log('Connected to WebSocket server');
});

socket.on('sensor_data', (data) => {
    console.log('Received sensor data:', data);
    // update web application display with new data
});