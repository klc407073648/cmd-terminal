import {useUserStore} from "./userStore";

const ADMIN_ROLE = 1;
export const NO_AUTH_EXEC_CMD = "非admin用户，无命令执行权限";

export function  isAdmin() {
  const { loginUser } = useUserStore();
  if (loginUser && loginUser.userRole !==ADMIN_ROLE) {
    return false;
  }

  return true;
}

export default {isAdmin,NO_AUTH_EXEC_CMD};
