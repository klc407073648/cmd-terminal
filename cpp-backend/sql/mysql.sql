-- auto-generated definition
create table if not exists cmdterminal.`user`
(
    id           bigint auto_increment comment 'id' primary key,
    username     varchar(256)                       null comment '用户昵称',
    userAccount  varchar(256)                       not null comment '账号',
    userPassword varchar(512)                       not null comment '密码',
    email        varchar(512)                       not null comment '邮箱',
    iphone       varchar(128)                       null comment '电话',
    avatarUrl    varchar(1024)                      null comment '用户头像',
    gender       tinyint                            null comment '性别',
    userStatus   int      default 0                 null comment '状态-0正常',
    createTime   datetime default CURRENT_TIMESTAMP null comment '创建时间',
    updateTime   datetime default CURRENT_TIMESTAMP null on update CURRENT_TIMESTAMP,
    idDelete     tinyint  default 0                 not null comment '是否删除',
    userRole     int      default 0                 not null comment '用户角色 0-普通用户 1-管理员',
    planetCode   varchar(512)                       null comment '星球编号',
    tags         varchar(1024)                      null comment '标签列表',
    profile      varchar(1024)                      null comment '个人简介'
) ENGINE = InnoDB COMMENT ='用户' character set = utf8;

-- 记录用户访问的记录表

-- 用户表设计时，考虑伙伴匹配系统、用户中心系统、开发api接口， 对于用户表的设计，兼容处理。（后端处理时，根据请求的项目不同，设计标签）

create table if not exists cmdterminal.`interface`
(
    `id`                 bigint                               not null auto_increment comment '主键' primary key,
    `name`               varchar(256)                         not null comment '名称',
    `description`        varchar(256)                         null comment '描述',
    `url`                varchar(512)                         null comment '接口地址',
    `method`             varchar(256)                         not null comment '请求类型',
    `requestParams`      text                                 null comment '请求参数',
    `requestHeader`      text                                 null comment '请求头',
    `responseHeader`     text                                 null comment '响应头',
    `status`             int default 0                        not null comment '接口状态（0-关闭，1-开启）',
    `type`               int default 0                        not null comment '接口类型（0-内部接口，1-第三方接口）',
    `createTime`         datetime default CURRENT_TIMESTAMP   not null comment '创建时间',
    `updateTime`         datetime default CURRENT_TIMESTAMP   not null on update CURRENT_TIMESTAMP comment '更新时间',
    `isDelete`           tinyint default 0                    not null comment   '是否删除(0-未删, 1-已删)'
) ENGINE = InnoDB COMMENT = '接口信息' character set = utf8;

create table if not exists cmdterminal.`log`
(
    `id`                 bigint                               not null auto_increment comment '主键' primary key,
    `userid`             bigint                               not null,
    `content`            varchar(1024)                        not null comment '执行内容',
    `type`               int default 0                        not null comment '日志类型（0-操作日志，1-运行日志）',
    `createTime`         datetime default CURRENT_TIMESTAMP   not null comment '创建时间',
    `updateTime`         datetime default CURRENT_TIMESTAMP   not null on update CURRENT_TIMESTAMP comment '更新时间',
    `isDelete`           tinyint default 0                    not null comment   '是否删除(0-未删, 1-已删)',
    CONSTRAINT fk_user_log_id FOREIGN KEY(userid) REFERENCES user(id) 
) ENGINE = InnoDB COMMENT = '日志表' character set = utf8;

--- 日志表



