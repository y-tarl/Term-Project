package dao.AvgScoreCount;

import com.model.teacher.AvgScoreCount;
import dao.Dao;
import dao.DaoException;

import java.util.ArrayList;

public interface AvgScoreCountDao extends Dao {
    public ArrayList<AvgScoreCount> Hejy_AvgScoreCount230128(String Cname,String Clname,String year) throws DaoException;

}
