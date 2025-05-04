const videos = [
	"assets/videos/1960sPlayground1.webm",
	"assets/videos/drone.webm",
	"assets/videos/forest.webm"
];


// check if the video has ended, activate function grabNextvideo()
document.querySelector('#videoContainer').addEventListener('ended', grabNextVideo, false);
// log the current video to the system. 
console.log(document.getElementById("videoContainer").getAttribute('src'))
function grabNextVideo(e) {
	console.log('next video');
	videoContainer.setAttribute('src', videos[Math.floor(Math.random()*videos.length)]);
	
}
