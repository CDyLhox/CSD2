const positiveVideos = [
	"assets/videos/1960sPlayground1.webm",
	"assets/videos/drone.webm",
	"assets/videos/forest.webm"
];

const negativeVideos = [
	"assets/videos/londerSmog.webm",
	"assets/videos/lightning.webm"
]
//TODO: make a single  grabnextvideo function which takes an argument for video type

// check if the video has ended, activate function grabNextvideo()
document.querySelector('#positiveVideoContainer').addEventListener('ended', grabNextPositiveVideo, false);
// log the current video to the system. 
console.log(document.getElementById("positiveVideoContainer").getAttribute('src'))
function grabNextPositiveVideo(e) {
	console.log('next video');
	
	positiveVideoContainer.setAttribute('onloadStart', this.volume= 0);
	positiveVideoContainer.setAttribute('src', positiveVideos[Math.floor(Math.random()*positiveVideos.length)]);
}



//same as above but for the negative Videos
document.querySelector('#negativeVideoContainer').addEventListener('ended', grabNextNegativeVideo, false);
// log the current video to the system. 
console.log(document.getElementById("negativeVideoContainer").getAttribute('src'))
function grabNextNegativeVideo(e) {
	console.log('next  sad video');
	
	negativeVideoContainer.setAttribute('onloadStart', this.volume= 0);
	negativeVideoContainer.setAttribute('src', negativeVideos[Math.floor(Math.random()*negativeVideos.length)]);
}

