
//help getting up and running via https://github.com/dariusk/examplebot
var Twit = require('twit');
var fs = require('fs');
var counter = 1; 
var T = new Twit(require('./config.js'));

function postTweet (){
// from https://www.npmjs.com/package/twit docs:
// post a tweet with media 

var b64content = fs.readFileSync('imgGenerator/outputImage'+counter+'.jpg', { encoding: 'base64' })
 
  // post the media to Twitter 
T.post('media/upload', { media_data: b64content }, function (err, data, response) { 
    // now we can reference the media and post a tweet (media will attach to the tweet) 
  var mediaIdStr = data.media_id_string
  var params = { status: '#blessed', media_ids: [mediaIdStr] }
 
  T.post('statuses/update', params, function (err, data, response) {
      console.log(data)
      console.log("posted a tweet");
    })
  })
  counter++;

}


postTweet(counter);

//~10 min interval, post tweets 560000
setInterval(function() {
  try {
    postTweet(counter); 
    }
 catch (e) {
    console.log(e);
  }
},560000);

