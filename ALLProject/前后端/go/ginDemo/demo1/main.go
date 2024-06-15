package main

import (
	"domo1/models"
	"fmt"
	"github.com/gin-gonic/gin"
	"log"
	"net/http"
)

var r = gin.Default()

func json() {
	r.GET("/ping", func(c *gin.Context) {
		c.JSON(http.StatusOK, gin.H{
			"message": "pong",
		})
		//c.String(200, "值是：%s", "你好")
	})
}

func html() {
	r.GET("/html", func(c *gin.Context) {
		c.HTML(http.StatusOK, "html模板.html", "")
	})
}

func upload() {

	r.POST("/upload", func(c *gin.Context) {
		form, _ := c.MultipartForm()
		files := form.File["files"]

		for _, file := range files {
			log.Println(file.Filename)
			// 上传文件至指定目录
			dst := "./template/" + file.Filename
			c.SaveUploadedFile(file, dst)
		}
		c.String(http.StatusOK, fmt.Sprintf("%d files uploaded!", len(files)))
	})
}

func db() {
	user := []models.TbUser{}
	models.DB.Find(&user)
	for _, e := range user {
		fmt.Println(e)
	}
}

func main() {
	json()
	html()
	upload()
	db()
	err := r.Run(":8088")
	if err != nil {
		return
	}
}
