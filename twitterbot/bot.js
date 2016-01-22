
// This function handles an incoming "request"
// And sends back out a "response";
var handleRequest = function (request, response) {
  response.writeHead(200, {'Content-Type': 'text/plain'});
  response.end('Hello World\n');
};

// HTTP module
var http = require('http');

// Create a server with the handleRequest callback
var server = http.createServer(handleRequest);
// Listen on port 8080
server.listen(8080);

console.log('Server started on port 8080');





//-------------------------

var Twit = require('twit');

var T = new Twit({
  consumer_key:         '', 
  consumer_secret:      '',
  access_token:         '',
  access_token_secret:  ''
});

// var restclient = require('node-restclient');


function postTweet (){
// from https://www.npmjs.com/package/twit docs:
// post a tweet with media 

var b64content = fs.readFileSync('/path/to/img', { encoding: 'base64' })
 
  // post the media to Twitter 
T.post('media/upload', { media_data: b64content }, function (err, data, response) { 
    // now we can reference the media and post a tweet (media will attach to the tweet) 
  var mediaIdStr = data.media_id_string
  var params = { status: 'loving life #nofilter', media_ids: [mediaIdStr] }
 
  T.post('statuses/update', params, function (err, data, response) {
      console.log(data)
      console.log("posted a tweet");
    })
  })
}

function generateImg(){
//possibly load imgs in from file, processing, p5, API..TBD


  postTweet();
}


//~10 min interval, post tweets
setInterval(function() {
  try {
    generateImg(); 
    }
 catch (e) {
    console.log(e);
  }
},560000);

