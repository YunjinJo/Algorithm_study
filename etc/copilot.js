function trafficLights(id) {
    var trafficLight = {
        id: id,
        state: 'red',
        timer: null,
        interval: null,
        intervalTime: 5000,
        intervalTimeRed: 1000,
        intervalTimeYellow: 2000,
        intervalTimeGreen: 3000,
        
        init: function() {
            this.interval = setInterval(function() {
                trafficLight.changeState();
            }, this.intervalTime);
        },
        
        changeState: function() {
            var newState = this.state;
            if (this.state == 'red') {
                newState = 'yellow';
            } else if (this.state == 'yellow') {
                newState = 'green';
            } else if (this.state == 'green') {
                newState = 'red';
            }
            this.setState(newState);
        },
        
        setState: function(state) {
            this.state = state;
            this.setLight(this.state);
        },
        
        setLight: function(state) {
            var light = document.getElementById(this.id);
            light.className = state;
        },
        
        startTimer: function() {
            this.timer = setTimeout(function() {
                trafficLight.changeState();
            }, this.intervalTime);
        },
        
        stopTimer: function() {
            clearTimeout(this.timer);
        }
    };
    
    trafficLight.init();
    return trafficLight;
}