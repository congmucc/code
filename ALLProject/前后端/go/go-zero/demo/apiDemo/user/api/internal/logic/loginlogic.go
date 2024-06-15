package logic

import (
	"apiDemo/common/jwts"
	"context"

	"apiDemo/user/api/internal/svc"
	"apiDemo/user/api/internal/types"

	"github.com/zeromicro/go-zero/core/logx"
)

type LoginLogic struct {
	logx.Logger
	ctx    context.Context
	svcCtx *svc.ServiceContext
}

func NewLoginLogic(ctx context.Context, svcCtx *svc.ServiceContext) *LoginLogic {
	return &LoginLogic{
		Logger: logx.WithContext(ctx),
		ctx:    ctx,
		svcCtx: svcCtx,
	}
}

func (l *LoginLogic) Login(req *types.LoginRequest) (resp string, err error) {
	// todo: add your logic here and delete this line
	token, err := jwts.GenToken(jwts.JwtPayLoad{
		UserID:   1,
		Username: req.UserName,
		Role:     1,
	}, l.svcCtx.Config.Auth.AccessSecret, l.svcCtx.Config.Auth.AccessExpire)

	if err != nil {
		return "", nil
	}
	return token, nil
}
