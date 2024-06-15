package logic

import (
	"context"
	"demo/user/rpc/user"

	"demo/video/api/internal/svc"
	"demo/video/api/internal/types"

	"github.com/zeromicro/go-zero/core/logx"
)

type GetVideoLogic struct {
	logx.Logger
	ctx    context.Context
	svcCtx *svc.ServiceContext
}

func NewGetVideoLogic(ctx context.Context, svcCtx *svc.ServiceContext) *GetVideoLogic {
	return &GetVideoLogic{
		Logger: logx.WithContext(ctx),
		ctx:    ctx,
		svcCtx: svcCtx,
	}
}

func (l *GetVideoLogic) GetVideo(req *types.VideoReq) (resp *types.VideoRes, err error) {
	user1, err1 := l.svcCtx.UserRpc.GetUser(context.Background(), &user.IdRequest{
		Id: "1",
	})
	if err1 != nil {
		return nil, err
	}

	return &types.VideoRes{
		Id:   req.Id,
		Name: user1.Name,
	}, nil

}
