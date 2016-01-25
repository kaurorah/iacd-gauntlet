
//help getting up and running via https://github.com/dariusk/examplebot
var Twit = require('twit');

var T = new Twit({
  consumer_key:         'lsqS9G2sj8EZdWHvUsbUA8o2p', 
  consumer_secret:      '2HdqZEU6lgydeRI7GMAhvVAlqz2V6BV9xIeG7IZ6eSHVTtuNDz',
  access_token:         '4840503778-HqaAunlofMeJBg9xtj1CY6aPPqNLBEKiQagihWj',
  access_token_secret:  'IkKO0FZmB0qaidab1XSmxAVlz3pq7YEUJTUKU6Ykq5mJk'
});


var botSearch = {q: "#bot", count: 10, result_type: "recent"}; 


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

}


postTweet();

//~10 min interval, post tweets 560000
setInterval(function() {
  try {
    generateImg(); 
    }
 catch (e) {
    console.log(e);
  }
},560000);

