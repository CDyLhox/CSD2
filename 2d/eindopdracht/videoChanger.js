const videos = [
	"assets/videos/1960sPlayground1.webm",
	"assets/videos/drone.webm",
	"assets/videos/forest.webm"
];


// check if the video has ended, activate function grabNextvideo()
document.querySelector('#positiveVideoContainer').addEventListener('ended', grabNextVideo, false);
// log the current video to the system. 
console.log(document.getElementById("positiveVideoContainer").getAttribute('src'))
function grabNextVideo(e) {
	console.log('next video');
	
	positiveVideoContainer.setAttribute('onloadStart', this.volume= 0);
	positiveVideoContainer.setAttribute('src', videos[Math.floor(Math.random()*videos.length)]);
}
