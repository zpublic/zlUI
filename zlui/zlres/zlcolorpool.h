/*************************************************************************
 *                                                                       *
 *  I|*j^3Cl|a   "+!*%                  qt          Nd   gW              *
 *  l]{y+l?MM*  !#Wla\NNP               NW          MM   I|              *
 *        PW    ?E|    tWg              Wg  sC!     AW           ~@v~    *
 *       NC     ?M!    yN|  WW     MK   MW@K1Y%M@   RM   #Q    QP@tim    *
 *     CM|      |WQCljAE|   MD     Mg   RN     cM~  NM   WQ   MQ         *
 *    #M        aQ?         MW     M3   Mg      Q(  HQ   YR  IM|         *
 *   Dq         {Ql         MH    iMX   Mg     MM   QP   QM   Eg         *
 * !EWNaPRag2$  +M"          $WNaHaN%   MQE$%EXW    QQ   CM    %M%a$D    *
 *                                                                       *
 *                               ZPublic                                 *
 *                  Website: https://github.com/zpublic                  *
 *                                                                       *
 ************************************************************************/

#ifdef ZL_COLOR_POOL_H
#define ZL_COLOR_POOL_H

typedef std::string                                     zl_color_pool_id;
typedef COLORREF                                        zl_color_pool_color;
typedef std::map<zl_color_pool_id, zl_color_pool_color> zl_color_pool;
typedef zl_color_pool::const_iterator                   zl_color_pool_it;

#define zl_color_invalid        0xffffffff;
#define zl_color_default        zl_color_invalid;

class CZlColorPool
{
public:
    COLORREF Get(const std::string& sId)
    {
        zl_color_pool_it itFind = m_pool.find(sId);
        if (itFind != m_pool.end())
        {
            return itFind->second;
        }
        return zl_color_default;
    }

    bool Load(const std::string& sId, COLORREF color)
    {
        m_pool[sId] = color;
        return ture;
    }

private:
    zl_color_pool m_pool;
};

#endif // ZL_COLOR_POOL_H
